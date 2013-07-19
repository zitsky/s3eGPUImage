/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eGPUImage.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eGPUImageGetContext_t)();
typedef     char *(*s3eGPUImageTake_t)(s3eGPUImageEventDoIt evnt, void * userData);

/**
 * struct that gets filled in by s3eGPUImageRegister
 */
typedef struct s3eGPUImageFuncs
{
    s3eGPUImageGetContext_t m_s3eGPUImageGetContext;
    s3eGPUImageTake_t m_s3eGPUImageTake;
} s3eGPUImageFuncs;

static s3eGPUImageFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x6bcefc1f, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eGPUImage");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x6bcefc1f, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eGPUImageAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eGPUImageGetContext()
{
    IwTrace(GPUIMAGE_VERBOSE, ("calling s3eGPUImage[0] func: s3eGPUImageGetContext"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eGPUImageGetContext();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

char * s3eGPUImageTake(s3eGPUImageEventDoIt evnt, void * userData)
{
    IwTrace(GPUIMAGE_VERBOSE, ("calling s3eGPUImage[1] func: s3eGPUImageTake"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    char * ret = g_Ext.m_s3eGPUImageTake(evnt, userData);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
