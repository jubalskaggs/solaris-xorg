/* $XdotOrg: xc/programs/Xserver/hw/xfree86/os-support/sunos/agpgart.h,v 1.2 2005/07/01 22:43:25 daniels Exp $ */
/*
 * AGPGART module version 0.99
 * Copyright (C) 1999 Jeff Hartmann
 * Copyright (C) 1999 Precision Insight, Inc.
 * Copyright (C) 1999 Xi Graphics, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * JEFF HARTMANN, OR ANY OTHER CONTRIBUTORS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
 * OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
 * INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Except as contained in this notice, the name of a copyright holder
 * shall not be used in advertising or otherwise to promote the sale, use
 * or other dealings in this Software without prior written authorization
 * of the copyright holder.
 */

#ifndef	_AGPGART_H
#define	_AGPGART_H

#pragma ident	"@(#)agpgart.h	1.2	06/10/25 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#define	AGP_NORMAL	0	/* mapped to user land, no cache */

typedef struct _agp_version {
	uint16_t	agpv_major;
	uint16_t	agpv_minor;
} agp_version_t;

typedef struct	_agp_info {
	agp_version_t	agpi_version;
	uint32_t	agpi_devid;	/* bridge vendor + device */
	uint32_t	agpi_mode;	/* mode of bridge */
	ulong_t		agpi_aperbase;	/* base of aperture */
	size_t		agpi_apersize;	/* aperture range size */
	uint32_t	agpi_pgtotal;	/* max number of pages in aperture */
	uint32_t	agpi_pgsystem;	/* same as pg_total */
	uint32_t	agpi_pgused;	/* NUMBER of currently used pages */
} agp_info_t;

typedef struct _agp_setup {
	uint32_t	agps_mode;
} agp_setup_t;

typedef struct _agp_allocate {
	int32_t		agpa_key;
	uint32_t	agpa_pgcount;
	uint32_t	agpa_type;
	uint32_t	agpa_physical;	/* for i810 only, private */
} agp_allocate_t;

typedef struct _agp_bind {
	int32_t		agpb_key;
	uint32_t	agpb_pgstart;
} agp_bind_t;

typedef struct _agp_unbind {
	int32_t		agpu_key;
	uint32_t	agpu_pri;	/* no use in solaris */
} agp_unbind_t;

#define	AGPIOC_BASE		'G'
#define	AGPIOC_INFO		_IOR(AGPIOC_BASE, 0, 100)
#define	AGPIOC_ACQUIRE		_IO(AGPIOC_BASE, 1)
#define	AGPIOC_RELEASE		_IO(AGPIOC_BASE, 2)
#define	AGPIOC_SETUP		_IOW(AGPIOC_BASE, 3, agp_setup_t)
#define	AGPIOC_ALLOCATE		_IOWR(AGPIOC_BASE, 4, agp_allocate_t)
#define	AGPIOC_DEALLOCATE	_IOW(AGPIOC_BASE, 5, int)
#define	AGPIOC_BIND		_IOW(AGPIOC_BASE, 6, agp_bind_t)
#define	AGPIOC_UNBIND		_IOW(AGPIOC_BASE, 7, agp_unbind_t)
#define	AGPIOC_IOREMAP		_IO(AGPIOC_BASE, 8)
#define	AGPIOC_IOREMAP_FREE	_IO(AGPIOC_BASE, 9)
#define	AGPIOC_READ		_IO(AGPIOC_BASE, 10)
#define	AGPIOC_WRITE		_IO(AGPIOC_BASE, 11)

/* AGP status register bits definition */
#define	AGPSTAT_RQ_MASK		0xff000000	/* target only */
#define	AGPSTAT_SBA		(0x1 << 9)	/* always 1 for 3.0 */
#define	AGPSTAT_OVER4G		(0x1 << 5)
#define	AGPSTAT_FW		(0x1 << 4)
#define	AGPSTAT_RATE_MASK	0x7
/* rate for 2.0 mode */
#define	AGP2_RATE_1X		0x1
#define	AGP2_RATE_2X		0x2
#define	AGP2_RATE_4X		0x4
/* AGP 3.0 only bits */
#define	AGPSTAT_ARQSZ_MASK	(0x7 << 13)	/* target only */
#define	AGPSTAT_CAL_MASK	(0x7 << 10)
#define	AGPSTAT_GART64B		(0x1 << 7)	/* target only */
#define	AGPSTAT_MODE3		(0x1 << 3)
/* Rate for 3.0 mode */
#define	AGP3_RATE_4X		0x1
#define	AGP3_RATE_8X		0x2

/* AGP command register bits definition */
#define	AGPCMD_RQ_MASK		0xff000000	/* master only */
#define	AGPCMD_SBAEN		(0x1 << 9)	/* must be 1 for 3.0 */
#define	AGPCMD_AGPEN		(0x1 << 8)
#define	AGPCMD_OVER4GEN		(0x1 << 5)
#define	AGPCMD_FWEN		(0x1 << 4)
#define	AGPCMD_RATE_MASK	0x7
/* AGP 3.0 only bits */
#define	AGP3_CMD_ARQSZ_MASK	(0x7 << 13)	/* master only */
#define	AGP3_CMD_CAL_MASK	(0x7 << 10)	/* target only */
#define	AGP3_CMD_GART64BEN	(0x1 << 7)	/* target only */

#define	AGP_DEVICE	"/dev/agpgart"

#ifdef __cplusplus
}
#endif

#endif /* _AGPGART_H */