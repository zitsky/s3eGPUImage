/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_GPUIMAGE_H
#define S3E_EXT_GPUIMAGE_H

#include "s3eTypes.h"

	struct s3eGPUImage;

	enum s3eGPUImageEventDoIt
	{
		s3eGPUImgInitial,
		s3eGPUImageDestroy,
		s3eGPUImgStartPreview,
		s3eGPUImgStartCapture,
		s3eGPUImgStopCapture,
		s3eGPUImgCopyFileToDash,
		s3eGPUImgGetFileName,
		s3eGPUImgGetTextureOut,
		s3eGPUImgSetTExtureIn
	};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the GPUImage extension is available.
 */
s3eBool s3eGPUImageAvailable();

void s3eGPUImageGetContext();

char * s3eGPUImageTake(s3eGPUImageEventDoIt evnt,void * userData);

S3E_END_C_DECL

#endif /* !S3E_EXT_GPUIMAGE_H */
