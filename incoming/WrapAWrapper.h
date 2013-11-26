//
//  WrapAWrapper.h
//  s3eGpuImageWrapper
//
//  Created by Лолшто on 19.07.13.
//  Copyright (c) 2013 Kiraline. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (*s3eAnalogLogBanan)(unsigned int,unsigned int*);

@interface WrapAWrapper : NSObject
{

}
+(WrapAWrapper*)sharedInstance;
-(void)InitialContext;
-(void)InitAudio;
-(void)StartCapture;
-(void)StartPreview;
-(void)StopPreview;
-(void)StopCapture;
-(void)ReleaseSystem;
-(void)CopyToHomeUserDirectory;
-(char*)GetFilename;
-(void)s3eSetTex:(char*)texId;
-(void*)s3eGetTexOut;
-(void)myGlGenTex:(unsigned int)asText Pointer:(unsigned int*)Pointer;
-(void)registerCallbackGLGEN:(s3eAnalogLogBanan)CBUse;
-(void)playVideoInTexture;
-(char*)getVideoFrame;
-(char)nowVideoPlaying;
-(void)stopVideoPlay;
-(void)stopAudioPlay;
-(char)saveToRolle;
-(char)onVideoFrame;
-(char)onCameraFrame;
-(void)pauseCamera;
-(void)unpauseCamera;
-(char)getVideoCaptureFlag;
-(void)preloadSound:(char*)fileName;
-(void)playSound:(char*)fileName;
-(void)showUIAlert:(void(^)(int))callback;
-(void)setupTextButton:(char*)textForButton;
-(void)changeToRussianLetter;
@end
