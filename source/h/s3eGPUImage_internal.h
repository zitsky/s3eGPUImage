/*
 * Internal header for the s3eGPUImage extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EGPUIMAGE_INTERNAL_H
#define S3EGPUIMAGE_INTERNAL_H

#include "s3eTypes.h"
#include "s3eGPUImage.h"
#include "s3eGPUImage_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eGPUImageInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eGPUImageInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eGPUImageTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eGPUImageTerminate_platform();
void s3eGPUImageGetContext_platform();

char * s3eGPUImageTake_platform(s3eGPUImageEventDoIt evnt, void * userData);
void s3eMyGLGenTextures(unsigned int col, unsigned int * point);


#endif /* !S3EGPUIMAGE_INTERNAL_H */