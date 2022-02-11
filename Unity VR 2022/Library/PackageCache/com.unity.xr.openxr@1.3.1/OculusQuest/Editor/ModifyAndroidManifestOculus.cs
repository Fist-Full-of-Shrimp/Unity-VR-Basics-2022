using System;
using System.IO;
using System.Text;
using System.Xml;
using UnityEditor.Build.Reporting;
using UnityEngine.XR.OpenXR.Features.OculusQuestSupport;

namespace UnityEditor.XR.OpenXR.Features.OculusQuestSupport
{
    internal class ModifyAndroidManifestOculus : OpenXRFeatureBuildHooks
    {
        public override int callbackOrder => 1;

        public override Type featureType => typeof(OculusQuestFeature);

        protected override void OnPreprocessBuildExt(BuildReport report)
        {
        }

        protected override void OnPostGenerateGradleAndroidProjectExt(string path)
        {
            var androidManifest = new AndroidManifest(GetManifestPath(path));
            androidManifest.AddOculusMetaData();
            androidManifest.Save();
        }

        protected override void OnPostprocessBuildExt(BuildReport report)
        {
        }

        private string _manifestFilePath;

        private string GetManifestPath(string basePath)
        {
            if (!string.IsNullOrEmpty(_manifestFilePath)) return _manifestFilePath;

            var pathBuilder = new StringBuilder(basePath);
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("src");
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("main");
            pathBuilder.Append(Path.DirectorySeparatorChar).Append("AndroidManifest.xml");
            _manifestFilePath = pathBuilder.ToString();

            return _manifestFilePath;
        }

        private class AndroidXmlDocument : XmlDocument
        {
            private string m_Path;
            protected XmlNamespaceManager nsMgr;
            public readonly string AndroidXmlNamespace = "http://schemas.android.com/apk/res/android";

            public AndroidXmlDocument(string path)
            {
                m_Path = path;
                using (var reader = new XmlTextReader(m_Path))
                {
                    reader.Read();
                    Load(reader);
                }

                nsMgr = new XmlNamespaceManager(NameTable);
                nsMgr.AddNamespace("android", AndroidXmlNamespace);
            }

            public string Save()
            {
                return SaveAs(m_Path);
            }

            public string SaveAs(string path)
            {
                using (var writer = new XmlTextWriter(path, new UTF8Encoding(false)))
                {
                    writer.Formatting = Formatting.Indented;
                    Save(writer);
                }

                return path;
            }
        }

        private class AndroidManifest : AndroidXmlDocument
        {
            private readonly XmlElement ApplicationElement;
            private readonly XmlElement ActivityIntentFilterElement;

            public AndroidManifest(string path) : base(path)
            {
                ApplicationElement = SelectSingleNode("/manifest/application") as XmlElement;
                ActivityIntentFilterElement = SelectSingleNode("/manifest/application/activity/intent-filter") as XmlElement;
            }

            private XmlAttribute CreateAndroidAttribute(string key, string value)
            {
                XmlAttribute attr = CreateAttribute("android", key, AndroidXmlNamespace);
                attr.Value = value;
                return attr;
            }

            private void UpdateOrCreateAttribute(XmlElement xmlParentElement, string tag, string key, string value)
            {
                // Get all child nodes that match the tag and see if value already exists
                var xmlNodeList = xmlParentElement.SelectNodes(tag);
                foreach (XmlNode node in xmlNodeList)
                {
                    foreach (XmlAttribute attrib in node.Attributes)
                    {
                        if (attrib.Value == value)
                        {
                            return;
                        }
                    }
                }

                XmlElement newElement = CreateElement(tag);
                newElement.SetAttribute(key, AndroidXmlNamespace, value);
                xmlParentElement.AppendChild(newElement);
            }

            internal void AddOculusMetaData()
            {
                UpdateOrCreateAttribute(ActivityIntentFilterElement,
                    "category",
                    "name",
                    "com.oculus.intent.category.VR");
            }
        }
    }
}
