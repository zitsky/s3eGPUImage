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
 	return (char*)[[WrapAWrapper sharedInstance] s3eGetTexOut];
 }

s3eResult s3eGPUImageInit_platform()
{
    // Add any platform-specific initialisation code here
    [[WrapAWrapper sharedInstance] InitAudio];
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
    
	char* texID;
	texID=(char*) userData;
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
            NSLog(@"CALL GPU Take START CAPTURE");
			[[WrapAWrapper sharedInstance] StartCapture];
			break;
		case s3eGPUImgStopCapture:
			[[WrapAWrapper sharedInstance] StopCapture];
			break;
		case s3eGPUImgCopyFileToDash:
            [[WrapAWrapper sharedInstance] saveToRolle];
			break;
		case s3eGPUImgGetFileName:
			break;
		case s3eGPUImgGetTextureOut:
			return ddGetTex(userData);
			break;
		case s3eGPUImgSetTextureIn:
			[[WrapAWrapper sharedInstance] s3eSetTex: texID];
			break;
        case 95:
            return [[WrapAWrapper sharedInstance] getVideoFrame];
            break;
        case 96:
            [[WrapAWrapper sharedInstance] playVideoInTexture];
            break;
        case 97:
            [[WrapAWrapper sharedInstance] stopVideoPlay];
            break;
        case 103:
            [[WrapAWrapper sharedInstance] stopAudioPlay];
            break;
        case 98:
            return (char*)[[WrapAWrapper sharedInstance] onVideoFrame];
            break;
        case 99:
            return (char*)[[WrapAWrapper sharedInstance] onCameraFrame];
            break;
        case 100:
            [[WrapAWrapper sharedInstance] saveToRolle];
            break;
        case 101:
            [[WrapAWrapper sharedInstance] pauseCamera];
            break;
        case 102:
            [[WrapAWrapper sharedInstance] unpauseCamera];
            break;
        case 143:
            return (char*)[[WrapAWrapper sharedInstance] getVideoCaptureFlag];
            break;
        case 155:
            [[WrapAWrapper sharedInstance] playSound:(char*)userData];
            break;

	case 156:
            [[WrapAWrapper sharedInstance] preloadSound:(char*)userData];
            break;
            
	}
    return 0;
}

void s3eMyGLGenTextures_platform(unsigned int col, unsigned int * point)
{
	[[WrapAWrapper sharedInstance] myGlGenTex: col Pointer: point];
}

void s3eRegisterGlGenTexturesCB_platform(s3eGPUImageGlGenTextures cb)
{
	[[WrapAWrapper sharedInstance] registerCallbackGLGEN:cb];
}