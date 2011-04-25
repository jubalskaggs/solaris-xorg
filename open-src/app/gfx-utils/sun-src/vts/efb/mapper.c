
/*
 * Copyright (c) 2006, 2009, Oracle and/or its affiliates. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <sys/types.h>
#include <stdio.h>
#include <sys/mman.h>

#include "gfx_common.h"		/* GFX Common definitions */
#include "graphicstest.h"
#include "libvtsSUNWefb.h"	/* Common VTS library definitions */

#include "X11/Xlib.h"
#include "gfx_vts.h"		/* VTS Graphics Test common routines */
#include "efb.h"


/*
 * map_me()
 */

void
map_me(return_packet *rp, int fd)
{
	struct efb_info  efb_info;
	struct efb_info  *pEFB;
	unsigned int	 value, chipType;
	

	pEFB = &efb_info;
	pEFB->fd = fd;

	/*
	 * map the registers & frame buffers memory
	 */
	if (efb_map_mem(pEFB, rp, GRAPHICS_ERR_OPEN) == -1) {
	    return;
	}

done:
	/*
	 * Unmap the registers & frame buffers memory
	 */
	if (efb_unmap_mem(pEFB, rp, GRAPHICS_ERR_OPEN) == -1) {
	    return;
	}

}	/* map_me() */


/* End of mapper.c */
