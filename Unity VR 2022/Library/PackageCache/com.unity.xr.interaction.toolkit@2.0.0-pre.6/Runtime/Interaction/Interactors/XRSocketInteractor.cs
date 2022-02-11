using System;
using System.Collections.Generic;
using UnityEngine.Rendering;
using UnityEngine.XR.Interaction.Toolkit.Utilities;

namespace UnityEngine.XR.Interaction.Toolkit
{
    /// <summary>
    /// Interactor used for holding interactables via a socket. This component is not designed to be attached to a controller
    /// (thus does not derive from <see cref="XRBaseControllerInteractor"/>) and instead will always attempt to select an interactable that it is
    /// hovering over (though will not perform exclusive selection of that interactable).
    /// </summary>
    [DisallowMultipleComponent]
    [AddComponentMenu("XR/XR Socket Interactor")]
    [HelpURL(XRHelpURLConstants.k_XRSocketInteractor)]
    public partial class XRSocketInteractor : XRBaseInteractor
    {
        [SerializeField]
        bool m_ShowInteractableHoverMeshes = true;
        /// <summary>
        /// Whether this socket should show a mesh at socket's attach point for Interactables that it is hovering over.
        /// </summary>
        public bool showInteractableHoverMeshes
        {
            get => m_ShowInteractableHoverMeshes;
            set => m_ShowInteractableHoverMeshes = value;
        }

        [SerializeField]
        Material m_InteractableHoverMeshMaterial;
        /// <summary>
        /// Material used for rendering interactable meshes on hover
        /// (a default material will be created if none is supplied).
        /// </summary>
        public Material interactableHoverMeshMaterial
        {
            get => m_InteractableHoverMeshMaterial;
            set => m_InteractableHoverMeshMaterial = value;
        }

        [SerializeField]
        Material m_InteractableCantHoverMeshMaterial;
        /// <summary>
        /// Material used for rendering interactable meshes on hover when there is already a selected object in the socket
        /// (a default material will be created if none is supplied).
        /// </summary>
        public Material interactableCantHoverMeshMaterial
        {
            get => m_InteractableCantHoverMeshMaterial;
            set => m_InteractableCantHoverMeshMaterial = value;
        }

        [SerializeField]
        bool m_SocketActive = true;
        /// <summary>
        /// Whether socket interaction is enabled.
        /// </summary>
        public bool socketActive
        {
            get => m_SocketActive;
            set => m_SocketActive = value;
        }

        [SerializeField]
        float m_InteractableHoverScale = 1f;
        /// <summary>
        /// Scale at which to render hovered Interactable.
        /// </summary>
        public float interactableHoverScale
        {
            get => m_InteractableHoverScale;
            set => m_InteractableHoverScale = value;
        }

        [SerializeField]
        float m_RecycleDelayTime = 1f;
        /// <summary>
        /// Sets the amount of time the socket will refuse hovers after an object is removed.
        /// </summary>
        public float recycleDelayTime
        {
            get => m_RecycleDelayTime;
            set => m_RecycleDelayTime = value;
        }

        float m_LastRemoveTime = -1f;

        /// <summary>
        /// The set of Interactables that this Interactor could possibly interact with this frame.
        /// This list is not sorted by priority.
        /// </summary>
        /// <seealso cref="IXRInteractor.GetValidTargets"/>
        protected List<IXRInteractable> unsortedValidTargets { get; } = new List<IXRInteractable>();

        readonly TriggerContactMonitor m_TriggerContactMonitor = new TriggerContactMonitor();

        readonly Dictionary<IXRInteractable, ValueTuple<MeshFilter, Renderer>[]> m_MeshFilterCache = new Dictionary<IXRInteractable, ValueTuple<MeshFilter, Renderer>[]>();

        /// <summary>
        /// Reusable list of type <see cref="MeshFilter"/> to reduce allocations.
        /// </summary>
        static readonly List<MeshFilter> s_MeshFilters = new List<MeshFilter>();

        /// <inheritdoc />
        protected override void Awake()
        {
            base.Awake();

            m_TriggerContactMonitor.interactionManager = interactionManager;
            m_TriggerContactMonitor.contactAdded += OnContactAdded;
            m_TriggerContactMonitor.contactRemoved += OnContactRemoved;

            CreateDefaultHoverMaterials();
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        /// <param name="other">The other <see cref="Collider"/> involved in this collision.</param>
        protected void OnTriggerEnter(Collider other)
        {
            m_TriggerContactMonitor.AddCollider(other);
        }

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        /// <param name="other">The other <see cref="Collider"/> involved in this collision.</param>
        protected void OnTriggerExit(Collider other)
        {
            m_TriggerContactMonitor.RemoveCollider(other);
        }

        /// <summary>
        /// Creates the default hover materials
        /// for <see cref="interactableHoverMeshMaterial"/> and <see cref="interactableCantHoverMeshMaterial"/> if necessary.
        /// </summary>
        protected virtual void CreateDefaultHoverMaterials()
        {
            if (m_InteractableHoverMeshMaterial != null && m_InteractableCantHoverMeshMaterial != null)
                return;

            var shaderName = GraphicsSettings.currentRenderPipeline ? "Universal Render Pipeline/Lit" : "Standard";
            var defaultShader = Shader.Find(shaderName);

            if (defaultShader == null)
            {
                Debug.LogWarning("Failed to create default materials for Socket Interactor," +
                    $" was unable to find \"{shaderName}\" Shader. Make sure the shader is included into the game build.", this);
                return;
            }

            if (m_InteractableHoverMeshMaterial == null)
            {
                m_InteractableHoverMeshMaterial = new Material(defaultShader);
                SetMaterialFade(m_InteractableHoverMeshMaterial, new Color(0f, 0f, 1f, 0.6f));
            }

            if (m_InteractableCantHoverMeshMaterial == null)
            {
                m_InteractableCantHoverMeshMaterial = new Material(defaultShader);
                SetMaterialFade(m_InteractableCantHoverMeshMaterial, new Color(1f, 0f, 0f, 0.6f));
            }
        }

        /// <summary>
        /// Sets Standard <paramref name="material"/> with Fade rendering mode
        /// and set <paramref name="color"/> as the main color.
        /// </summary>
        /// <param name="material">The <see cref="Material"/> whose properties will be set.</param>
        /// <param name="color">The main color to set.</param>
        static void SetMaterialFade(Material material, Color color)
        {
            material.SetOverrideTag("RenderType", "Transparent");
            material.SetFloat(ShaderPropertyLookup.mode, 2f);
            material.SetInt(ShaderPropertyLookup.srcBlend, (int)BlendMode.SrcAlpha);
            material.SetInt(ShaderPropertyLookup.dstBlend, (int)BlendMode.OneMinusSrcAlpha);
            material.SetInt(ShaderPropertyLookup.zWrite, 0);
            // ReSharper disable StringLiteralTypo
            material.DisableKeyword("_ALPHATEST_ON");
            material.EnableKeyword("_ALPHABLEND_ON");
            material.DisableKeyword("_ALPHAPREMULTIPLY_ON");
            // ReSharper restore StringLiteralTypo
            material.renderQueue = (int)RenderQueue.Transparent;
            material.SetColor(GraphicsSettings.currentRenderPipeline ? ShaderPropertyLookup.baseColor : ShaderPropertyLookup.color, color);
        }

        /// <inheritdoc />
        protected override void OnHoverEntering(HoverEnterEventArgs args)
        {
            base.OnHoverEntering(args);

            s_MeshFilters.Clear();
            args.interactableObject.transform.GetComponentsInChildren(true, s_MeshFilters);
            if (s_MeshFilters.Count == 0)
                return;

            var interactableTuples = new ValueTuple<MeshFilter, Renderer>[s_MeshFilters.Count];
            for (var i = 0; i < s_MeshFilters.Count; ++i)
            {
                var meshFilter = s_MeshFilters[i];
                interactableTuples[i] = (meshFilter, meshFilter.GetComponent<Renderer>());
            }
            m_MeshFilterCache.Add(args.interactableObject, interactableTuples);
        }

        /// <inheritdoc />
        protected override void OnHoverExiting(HoverExitEventArgs args)
        {
            base.OnHoverExiting(args);
            m_MeshFilterCache.Remove(args.interactableObject);
        }

        /// <inheritdoc />
        protected override void OnSelectExiting(SelectExitEventArgs args)
        {
            base.OnSelectExiting(args);
            m_LastRemoveTime = Time.time;
        }

        /// <inheritdoc />
        public override void ProcessInteractor(XRInteractionUpdateOrder.UpdatePhase updatePhase)
        {
            base.ProcessInteractor(updatePhase);

            if (updatePhase == XRInteractionUpdateOrder.UpdatePhase.Dynamic)
            {
                // An explicit check for isHoverRecycleAllowed is done since an interactable may have been deselected
                // after this socket was updated by the manager, such as when a later Interactor takes the selection
                // from this socket. The recycle delay time could cause the hover to be effectively disabled.
                if (m_ShowInteractableHoverMeshes && hasHover && isHoverRecycleAllowed)
                    DrawHoveredInteractables();
            }
        }

        Matrix4x4 GetHoverMeshMatrix(IXRInteractable interactable, MeshFilter meshFilter, float hoverScale)
        {
            var interactableAttachTransform = interactable.GetAttachTransform(this);
            var attachOffset = meshFilter.transform.position - interactableAttachTransform.position;
            var interactableLocalPosition = interactableAttachTransform.InverseTransformDirection(attachOffset) * hoverScale;
            var interactableLocalRotation = Quaternion.Inverse(Quaternion.Inverse(meshFilter.transform.rotation) * interactableAttachTransform.rotation);

            var interactorAttachTransform = GetAttachTransform(interactable);
            var position = interactorAttachTransform.position + interactorAttachTransform.rotation * interactableLocalPosition;
            var rotation = interactorAttachTransform.rotation * interactableLocalRotation;
            var scale = meshFilter.transform.lossyScale * hoverScale;

            return Matrix4x4.TRS(position, rotation, scale);
        }

        /// <summary>
        /// Unity calls this method automatically in order to draw the Interactables that are currently being hovered over.
        /// </summary>
        protected virtual void DrawHoveredInteractables()
        {
            if (m_InteractableHoverScale <= 0f)
                return;

            var materialToDrawWith = hasSelection ? m_InteractableCantHoverMeshMaterial : m_InteractableHoverMeshMaterial;
            if (materialToDrawWith == null)
                return;

            var mainCamera = Camera.main;
            if (mainCamera == null)
                return;

            foreach (var interactable in interactablesHovered)
            {
                if (interactable == null)
                    continue;

                if (IsSelecting(interactable))
                    continue;

                if (!m_MeshFilterCache.TryGetValue(interactable, out var interactableTuples))
                    continue;

                if (interactableTuples == null || interactableTuples.Length == 0)
                    continue;

                foreach (var tuple in interactableTuples)
                {
                    var meshFilter = tuple.Item1;
                    var meshRenderer = tuple.Item2;
                    if (!ShouldDrawHoverMesh(meshFilter, meshRenderer, mainCamera))
                        continue;

                    var matrix = GetHoverMeshMatrix(interactable, meshFilter, m_InteractableHoverScale);
                    var sharedMesh = meshFilter.sharedMesh;
                    for (var submeshIndex = 0; submeshIndex < sharedMesh.subMeshCount; ++submeshIndex)
                    {
                        Graphics.DrawMesh(
                            sharedMesh,
                            matrix,
                            materialToDrawWith,
                            gameObject.layer,
                            null, // Draw mesh in all cameras (default value)
                            submeshIndex);
                    }
                }
            }
        }

        /// <inheritdoc />
        public override void GetValidTargets(List<IXRInteractable> targets)
        {
            SortingHelpers.SortByDistanceToInteractor(this, unsortedValidTargets, targets);
        }

        /// <inheritdoc />
        public override bool isHoverActive => base.isHoverActive && m_SocketActive;

        /// <inheritdoc />
        public override bool isSelectActive => base.isSelectActive && m_SocketActive;

        /// <inheritdoc />
        public override XRBaseInteractable.MovementType? selectedInteractableMovementTypeOverride => XRBaseInteractable.MovementType.Instantaneous;

        /// <inheritdoc />
        public override bool CanHover(IXRHoverInteractable interactable)
        {
            return base.CanHover(interactable) && isHoverRecycleAllowed;
        }

        bool isHoverRecycleAllowed => m_LastRemoveTime < 0f || m_RecycleDelayTime <= 0f || (Time.time > m_LastRemoveTime + m_RecycleDelayTime);

        /// <inheritdoc />
        public override bool CanSelect(IXRSelectInteractable interactable)
        {
            return base.CanSelect(interactable) && ((!hasSelection && !interactable.isSelected) || IsSelecting(interactable));
        }

        /// <summary>
        /// Unity calls this method automatically in order to determine whether the Mesh should be drawn.
        /// </summary>
        /// <param name="meshFilter">The <see cref="MeshFilter"/> which will be drawn when returning <see langword="true"/>.</param>
        /// <param name="meshRenderer">The <see cref="Renderer"/> on the same <see cref="GameObject"/> as the <paramref name="meshFilter"/>.</param>
        /// <param name="mainCamera">The Main Camera.</param>
        /// <returns>Returns <see langword="true"/> if the Mesh should be drawn. Otherwise, returns <see langword="false"/>.</returns>
        /// <seealso cref="DrawHoveredInteractables"/>
        protected virtual bool ShouldDrawHoverMesh(MeshFilter meshFilter, Renderer meshRenderer, Camera mainCamera)
        {
            // TODO By only checking the main camera culling flags, but drawing the mesh in all cameras,
            // aren't we ignoring the culling mask of non-main cameras? Or does DrawMesh handle culling
            // automatically, making some of this evaluation unnecessary?
            var cullingMask = mainCamera.cullingMask;
            return meshFilter != null && (cullingMask & (1 << meshFilter.gameObject.layer)) != 0 && meshRenderer != null && meshRenderer.enabled;
        }

        /// <inheritdoc />
        protected override void OnRegistered(InteractorRegisteredEventArgs args)
        {
            base.OnRegistered(args);
            args.manager.interactableRegistered += OnInteractableRegistered;
            args.manager.interactableUnregistered += OnInteractableUnregistered;

            // Attempt to resolve any colliders that entered this trigger while this was not subscribed,
            // and filter out any targets that were unregistered while this was not subscribed.
            m_TriggerContactMonitor.interactionManager = args.manager;
            m_TriggerContactMonitor.ResolveUnassociatedColliders();
            XRInteractionManager.RemoveAllUnregistered(args.manager, unsortedValidTargets);
        }

        /// <inheritdoc />
        protected override void OnUnregistered(InteractorUnregisteredEventArgs args)
        {
            base.OnUnregistered(args);
            args.manager.interactableRegistered -= OnInteractableRegistered;
            args.manager.interactableUnregistered -= OnInteractableUnregistered;
        }

        void OnInteractableRegistered(InteractableRegisteredEventArgs args)
        {
            m_TriggerContactMonitor.ResolveUnassociatedColliders(args.interactableObject);
            if (m_TriggerContactMonitor.IsContacting(args.interactableObject) && !unsortedValidTargets.Contains(args.interactableObject))
                unsortedValidTargets.Add(args.interactableObject);
        }

        void OnInteractableUnregistered(InteractableUnregisteredEventArgs args)
        {
            unsortedValidTargets.Remove(args.interactableObject);
        }

        void OnContactAdded(IXRInteractable interactable)
        {
            if (!unsortedValidTargets.Contains(interactable))
                unsortedValidTargets.Add(interactable);
        }

        void OnContactRemoved(IXRInteractable interactable)
        {
            unsortedValidTargets.Remove(interactable);
        }

        struct ShaderPropertyLookup
        {
            public static readonly int mode = Shader.PropertyToID("_Mode");
            public static readonly int srcBlend = Shader.PropertyToID("_SrcBlend");
            public static readonly int dstBlend = Shader.PropertyToID("_DstBlend");
            public static readonly int zWrite = Shader.PropertyToID("_ZWrite");
            public static readonly int baseColor = Shader.PropertyToID("_BaseColor");
            public static readonly int color = Shader.PropertyToID("_Color"); // Legacy
        }
    }
}
