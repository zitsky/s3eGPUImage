/*
Generic implementation of the s3eGPUImage extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eGPUImage_internal.h"
s3eResult s3eGPUImageInit()
{
    //Add any generic initialisation code here
    return s3eGPUImageInit_platform();
}

void s3eGPUImageTerminate()
{
    //Add any generic termination code here
    s3eGPUImageTerminate_platform();
}

void s3eGPUImageGetContext()
{
	s3eGPUImageGetContext_platform();
}

char * s3eGPUImageTake(s3eGPUImageEventDoIt evnt, void * userData)
{
	return s3eGPUImageTake_platform(evnt, userData);
}

void s3eMyGLGenTextures(unsigned int col, unsigned int * point)
{
	s3eMyGLGenTextures_platform(col,point);
}