/*
 * iphone-specific implementation of the s3eGPUImage extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eGPUImage_internal.h"
#include "WrapAWrapper.h"
#include "s3eEdk_iphone.h"

 char secretData[24];

 char * ddGetTex(void * pointer)
 {
 	unsigned int ffr=0;
 	ffr=(unsigned int)[[WrapAWrapper sharedInstance] s3eGetTexOut];
       return (char*)ffr;
 }

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
	//s3eEdkIPhoneSetAudioInputEnabled(true);
	[[WrapAWrapper sharedInstance] InitialContext];
}

char * s3eGPUImageTake_platform(s3eGPUImageEventDoIt evnt, void * userData)
{
	unsigned int texID;
	texID=(unsigned int) userData;
	switch(evnt)
	{
		case s3eGPUImgInitial:
			break;
		case s3eGPUImageDestroy:
			[[WrapAWrapper sharedInstance] ReleaseSystem];
			break;
		case s3eGPUImgStartPreview:
			[[WrapAWrapper sharedInstance] StartPreview];
			break;
		case s3eGPUImgStartCapture:
			[[WrapAWrapper sharedInstance] StartCapture];
			break;
		case s3eGPUImgStopCapture:
			[[WrapAWrapper sharedInstance] StopCapture];
			break;
		case s3eGPUImgCopyFileToDash:
			break;
		case s3eGPUImgGetFileName:
			break;
		case s3eGPUImgGetTextureOut:
			return ddGetTex(userData);
			break;
		case s3eGPUImgSetTextureIn:
			[[WrapAWrapper sharedInstance] s3eSetTex: texID];
			break;
	}
    return 0;
}

void s3eMyGLGenTextures_platform(unsigned int col, unsigned int * point)
{
	[[WrapAWrapper sharedInstance] myGlGenTex: col pointer: point];
}