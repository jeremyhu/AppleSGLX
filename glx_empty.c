#include "glxclient.h"
#include "glxextensions.h"
#include "glcontextmodes.h"

/*
** GLX_SGI_swap_control
*/
int glXSwapIntervalSGI(int interval)
{
    (void)interval;
    return 0;
}


/*
** GLX_MESA_swap_control
*/
int glXSwapIntervalMESA(unsigned int interval)
{
   (void) interval;
   return GLX_BAD_CONTEXT;
}
 

int glXGetSwapIntervalMESA(void)
{
    return 0;
}


/*
** GLX_MESA_swap_frame_usage
*/

GLint glXBeginFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
    int   status = GLX_BAD_CONTEXT;
    (void) dpy;
    (void) drawable;
    return status;
}

    
GLint glXEndFrameTrackingMESA(Display *dpy, GLXDrawable drawable)
{
   int status = GLX_BAD_CONTEXT;
   (void) dpy;
   (void) drawable;
   return status;
}


GLint glXGetFrameUsageMESA(Display *dpy, GLXDrawable drawable,
				    GLfloat *usage)
{
   int status = GLX_BAD_CONTEXT;
   (void) dpy;
   (void) drawable;
   (void) usage;
   return status;
}

GLint glXQueryFrameTrackingMESA(Display *dpy, GLXDrawable drawable,
					 int64_t *sbc, int64_t *missedFrames,
					 GLfloat *lastMissedUsage)
{
   int status = GLX_BAD_CONTEXT;
   (void) dpy;
   (void) drawable;
   (void) sbc;
   (void) missedFrames;
   (void) lastMissedUsage;
   return status;
}

/*
** GLX_SGI_video_sync
*/
int glXGetVideoSyncSGI(unsigned int *count)
{
    (void) count;
    return GLX_BAD_CONTEXT;
}

int glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int *count)
{
    (void) count;
    return GLX_BAD_CONTEXT;
}


/*
** GLX_SGIX_swap_group
*/
void glXJoinSwapGroupSGIX(Display *dpy, GLXDrawable drawable,
				   GLXDrawable member)
{
   (void) dpy;
   (void) drawable;
   (void) member;
}


/*
** GLX_SGIX_swap_barrier
*/
void glXBindSwapBarrierSGIX(Display *dpy, GLXDrawable drawable,
				     int barrier)
{
   (void) dpy;
   (void) drawable;
   (void) barrier;
}

Bool glXQueryMaxSwapBarriersSGIX(Display *dpy, int screen, int *max)
{
   (void) dpy;
   (void) screen;
   (void) max;
   return False;
}


/*
** GLX_OML_sync_control
*/
Bool glXGetSyncValuesOML(Display *dpy, GLXDrawable drawable,
				  int64_t *ust, int64_t *msc, int64_t *sbc)
{
   (void) dpy;
   (void) drawable;
   (void) ust;
   (void) msc;
   (void) sbc;
   return False;
}

int64_t glXSwapBuffersMscOML(Display *dpy, GLXDrawable drawable,
				      int64_t target_msc, int64_t divisor,
				      int64_t remainder)
{
   (void) dpy;
   (void) drawable;
   (void) target_msc;
   (void) divisor;
   (void) remainder;
   return 0;
}


Bool glXWaitForMscOML(Display * dpy, GLXDrawable drawable,
			       int64_t target_msc, int64_t divisor,
			       int64_t remainder, int64_t *ust,
			       int64_t *msc, int64_t *sbc)
{
   (void) dpy;
   (void) drawable;
   (void) target_msc;
   (void) divisor;
   (void) remainder;
   (void) ust;
   (void) msc;
   (void) sbc;
   return False;
}


Bool glXWaitForSbcOML(Display * dpy, GLXDrawable drawable,
			       int64_t target_sbc, int64_t *ust,
			       int64_t *msc, int64_t *sbc )
{
    (void) dpy;
    (void) drawable;
    (void) target_sbc;
    (void) ust;
    (void) msc;
    (void) sbc;
    return False;
}


/**
 * GLX_MESA_allocate_memory
 */
/*@{*/

PUBLIC void *glXAllocateMemoryMESA(Display *dpy, int scrn,
				   size_t size, float readFreq,
				   float writeFreq, float priority)
{
   (void) dpy;
   (void) scrn;
   (void) size;
   (void) readFreq;
   (void) writeFreq;
   (void) priority;
   return NULL;
}


PUBLIC void glXFreeMemoryMESA(Display *dpy, int scrn, void *pointer)
{
#ifdef __DRI_ALLOCATE
   __GLXscreenConfigs * const psc = GetGLXScreenConfigs( dpy, scrn );

   if (psc && psc->allocate)
	 (*psc->allocate->freeMemory)(psc->__driScreen, pointer);

#else
   (void) dpy;
   (void) scrn;
   (void) pointer;
#endif /* GLX_DIRECT_RENDERING */
}


PUBLIC GLuint glXGetMemoryOffsetMESA( Display *dpy, int scrn,
				      const void *pointer )
{
   (void) dpy;
   (void) scrn;
   (void) pointer;
   return ~0L;
}

Bool glXReleaseBuffersMESA( Display *dpy, GLXDrawable d )
{
   (void) dpy;
   (void) d;
   return False;
}


PUBLIC GLXPixmap glXCreateGLXPixmapMESA( Display *dpy, XVisualInfo *visual,
					 Pixmap pixmap, Colormap cmap )
{
   (void) dpy;
   (void) visual;
   (void) pixmap;
   (void) cmap;
   return 0;
}


/**
 * GLX_MESA_copy_sub_buffer
 */
void glXCopySubBufferMESA(Display *dpy, GLXDrawable drawable,
				   int x, int y, int width, int height)
{
    (void) dpy;
    (void) drawable;
    (void) x;
    (void) y;
    (void) width;
    (void) height;
}


PUBLIC int glXQueryGLXPbufferSGIX(Display *dpy, GLXDrawable drawable,
		       int attribute, unsigned int *value)
{
    (void) dpy;
    (void) drawable;
    (void) attribute;
    (void) value;
    return 0;
}

PUBLIC GLXDrawable glXCreateGLXPbufferSGIX(Display *dpy, GLXFBConfig config,
			unsigned int width, unsigned int height,
			int *attrib_list) {
    (void) dpy;
    (void) config;
    (void) width;
    (void) height;
    (void) attrib_list;
    return None;
}

PUBLIC GLX_ALIAS_VOID(glXDestroyGLXPbufferSGIX,
		      (Display *dpy, GLXDrawable pbuf),
		      (dpy, pbuf),
		      glXDestroyPbuffer)
    
PUBLIC GLX_ALIAS_VOID(glXSelectEventSGIX,
		      (Display *dpy, GLXDrawable drawable, unsigned long mask),
		      (dpy, drawable, mask),
		      glXSelectEvent)

PUBLIC GLX_ALIAS_VOID(glXGetSelectedEventSGIX,
		      (Display *dpy, GLXDrawable drawable, unsigned long *mask),
		      (dpy, drawable, mask),
		      glXGetSelectedEvent)