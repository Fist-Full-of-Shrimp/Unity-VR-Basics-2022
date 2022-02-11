package com.unity.oculus;

import android.app.Activity;
import android.view.Surface;
import android.view.SurfaceView;
import android.util.Log;
import android.view.ViewGroup;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Build;
import java.util.Locale;
import com.unity3d.player.UnityPlayer;

public class OculusUnity
{
    UnityPlayer player;
    Activity activity;
    SurfaceView glView;

    public void initOculus()
    {
        Log.d("Unity", "initOculus Java!");
        activity = UnityPlayer.currentActivity;

        activity.runOnUiThread(() -> {

            ViewGroup vg = (ViewGroup) activity.findViewById(android.R.id.content);
            player = null;
            for (int i = 0; i < vg.getChildCount(); ++i) {
                if (vg.getChildAt(i) instanceof UnityPlayer) {
                    player = (UnityPlayer) vg.getChildAt(i);
                    break;
                }
            }

            if (player == null) {
                Log.e("Unity", "Failed to find UnityPlayer view!");
                return;
            }

            glView = null;
            int surfaceViewId = activity.getResources().getIdentifier("unitySurfaceView", "id", activity.getPackageName());

            if(surfaceViewId == 0){
                Log.e("Unity", "Failed to find SurfaceView Identifier!");
            }
            else{
                SurfaceView view = activity.findViewById(surfaceViewId);

                if(view != null && view instanceof SurfaceView){
                    glView = view;
                }  
            }

            if (glView == null) {
                Log.e("Unity", "Failed to find GlView!");
            }

            Log.d("Unity", "Oculus UI thread done.");

            initComplete(glView.getHolder().getSurface());
        });
    }

    public void pauseOculus()
    {

    }

    public void resumeOculus()
    {

    }

    public void destroyOculus()
    {

    }

    private native void initComplete(Surface glView);

	
    public static void loadLibrary(String name) {
		Log.d("Unity", "loading library " + name);
        java.lang.System.loadLibrary(name);
    }

    public static boolean getLowOverheadMode() {
        boolean ret = false;

        try
        {
            Activity activity = UnityPlayer.currentActivity;
            ApplicationInfo appInfo = activity.getPackageManager().getApplicationInfo(activity.getPackageName(), PackageManager.GET_META_DATA);
            Bundle bundle = appInfo.metaData;
            ret = bundle.getBoolean("com.unity.xr.oculus.LowOverheadMode");
        }
        catch (Exception e)
        {
            Log.d("Unity", "Oculus XR Plugin init error");
        }

        return ret;
    }

    public static boolean getIsOnOculusHardware() {
        String manufacturer = android.os.Build.MANUFACTURER;
        return manufacturer.toLowerCase(Locale.ENGLISH).contains("oculus");
    }
}
