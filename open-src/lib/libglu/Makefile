###############################################################################
#
# Copyright (c) 2006, 2016, Oracle and/or its affiliates. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
#

# Package name used in tarballs
MODULE_NAME=glu

# Package metadata
UPSTREAM	= The Mesa 3-D Graphics Library
UPSTREAM_URL	= http://mesa3d.org/
UPSTREAM_SET	= yes

MODULE_LICENSE          = Mesa License (Mixed: MIT, LGPLv2, others)
MODULE_LICENSE_SET      = yes
MODULE_LICENSE_PREPEND	= $(GPL_CHOICE_FILE)
MODULE_DESC		= the Mesa 3-D Graphics Libraries
ORACLE_TPNO		= 9926

# ARC cases that covered this module
# LSARC/2005/109 MESA, Open Source OpenGL clone
MODULE_ARC_CASES = LSARC/2005/109

# Version number (used in path names)
MODULE_VERSION=9.0.0

# Checksums for upstream tarball
TARBALL_MD5  = be9249132ff49275461cf92039083030
TARBALL_SHA1 = c2814bbaf1e60e28a75ec80f4646047c0da742bd

# Download site for source
SOURCE_URL=ftp://ftp.freedesktop.org/pub/mesa/glu/$(SOURCE_TARBALL_NAME)
SOURCE_URL_SET=yes
GIT_URL=$(FDO_GIT_URL)/mesa/glu
GIT_URL_SET=yes

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES=

# Use -KPIC instead of -Kpic because we have too many symbols on SPARC
DELIBTOOLIZE_FLAGS_sparc = -P
DELIBTOOLIZE_FLAGS_i386 = 
DELIBTOOLIZE_FLAGS = $(DELIBTOOLIZE_FLAGS_$(MACH))

# pkg-config files to update
FIX_PC_FILES=glu.pc.in

# Need to find libdrm in protodir at build time, since libGL links to it
MODULE_LDFLAGS= -L$(PROTODIR)$(X11_SERVERLIBS_DIR)$(ARCHLIBSUBDIR)

# Override LDFLAGS passed to configure to not include CFLAGS, since that
# breaks building libGLU with Sun Studio C++ compiler
MODULE_CONFIG_ENV = LDFLAGS="$(DEFAULT_CONFIG_LDFLAGS) $(ARCH_FLAGS) $(MODTYPE_LDFLAGS) $(MODULE_CFLAGS) $(MODULE_LDFLAGS)"

# Add proto area to path to find makedepend
MODULE_BUILD_ENV = PATH="$(PROTODIR)/$(X11_BIN_DIR):$(PATH)"
MODULE_CONFIG_ENV += $(MODULE_BUILD_ENV)

# Need to use GNU Make to build
MODULE_MAKE=$(GNUMAKE)
MODULE_MAKE_SET=yes

# Need to build with gcc
MODULE_COMPILER=gcc
MODULE_COMPILER_SET=yes

# Cos of 23185711 - disable parfait temporarily
USE_PARFAIT=no

### Include common rulesets
include ../Makefile.inc

HEADERS_TO_MOVE = glu.h glu_mangle.h
HEADERS_TO_DIRECT_LINK = glu.h
LIBRARY_TO_LINK = libGLU.so.1

# Run just once after all other install steps are done for both 32/64-bit
install: install_ogl_layout

install_ogl_layout:
	mv -f $(PROTODIR)/usr/include/GL/glu.h \
	      $(PROTODIR)/usr/include/GL/glu_mangle.h \
	      $(PROTODIR)/usr/include/mesa/
	ln -s $(HEADERS_TO_DIRECT_LINK:%=../mesa/%) \
		$(PROTODIR)/usr/include/GL
	mkdir -p $(PROTODIR)/usr/lib/GL/$(SUBDIR64) \
		$(PROTODIR)/usr/lib/mesa/$(SUBDIR64)
	mv -f $(LIBRARY_TO_LINK:%=$(PROTODIR)/usr/lib/%) \
		$(PROTODIR)/usr/lib/mesa/
	mv -f $(LIBRARY_TO_LINK:%=$(PROTODIR)/usr/lib/$(SUBDIR64)/%) \
		$(PROTODIR)/usr/lib/mesa/$(SUBDIR64)/
	-rm -f $(PROTODIR)/usr/lib/mesa/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/mesa/libGLU.so
	-rm -f $(PROTODIR)/usr/lib/mesa/$(SUBDIR64)/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/mesa/$(SUBDIR64)/libGLU.so
	(cd $(PROTODIR)/usr/lib/GL; rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=../mesa/%) .)
	-rm -f $(PROTODIR)/usr/lib/GL/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/GL/libGLU.so
	(cd $(PROTODIR)/usr/lib/GL/$(SUBDIR64); rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=../../mesa/$(SUBDIR64)/%) .)
	-rm -f $(PROTODIR)/usr/lib/GL/$(SUBDIR64)/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/GL/$(SUBDIR64)/libGLU.so
	(cd $(PROTODIR)/usr/lib; rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=GL/%) .)
	-rm -f $(PROTODIR)/usr/lib/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/libGLU.so
	(cd $(PROTODIR)/usr/lib/$(SUBDIR64); rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=../GL/$(SUBDIR64)/%) .)
	-rm -f $(PROTODIR)/usr/lib/$(SUBDIR64)/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/lib/$(SUBDIR64)/libGLU.so
	(cd $(PROTODIR)/usr/X11/lib; rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=GL/%) .)
	-rm -f $(PROTODIR)/usr/X11/lib/libGLU.so
	ln -s libGLU.so.1 $(PROTODIR)/usr/X11/lib/libGLU.so
	(cd $(PROTODIR)/usr/X11/lib/$(SUBDIR64); rm -f $(LIBRARY_TO_LINK) ; \
	 ln -s $(LIBRARY_TO_LINK:%=../GL/$(SUBDIR64)/%) .)
	-rm -f $(PROTODIR)/usr/X11/lib/$(SUBDIR64)/libGLU.so 
	ln -s libGLU.so.1 $(PROTODIR)/usr/X11/lib/$(SUBDIR64)/libGLU.so
