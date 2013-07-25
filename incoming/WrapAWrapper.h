//
//  WrapAWrapper.h
//  s3eGpuImageWrapper
//
//  Created by Лолшто on 19.07.13.
//  Copyright (c) 2013 Kiraline. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WrapAWrapper : NSObject
{

}
+(WrapAWrapper*)sharedInstance;
-(void)InitialContext;
-(void)StartCapture;
-(void)StartPreview;
-(void)StopPreview;
-(void)StopCapture;
-(void)ReleaseSystem;
-(void)CopyToHomeUserDirectory;
-(char*)GetFilename;
-(void)s3eSetTex:(unsigned int)texId;
-(unsigned int)s3eGetTexOut;
-(void)myGlGenTex:(unsigned int)asText Pointer:(unsigned int*)Pointer;
@end
