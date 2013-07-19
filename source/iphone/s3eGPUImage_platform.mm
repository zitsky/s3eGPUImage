/*
 * iphone-specific implementation of the s3eGPUImage extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGPUImage_internal.h"

s3eResult s3eGPUImageInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eGPUImageTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eGPUImageGetContext_platform()
{
}

char * s3eGPUImageTake_platform(s3eGPUImageEventDoIt evnt, void * userData)
{
    return 0;
}
