###############################################################################
#
# Xp 1.x Makefile
#
# Copyright (c) 2008, 2015, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=libXp

# Version number (used in path names)
MODULE_VERSION=1.0.3

# Checksums for upstream tarball
TARBALL_MD5   = df9e6bf0d988de6694f08693b8002079
TARBALL_SHA1  = 9e10371ca8961b50c2d69150a88fc031455699d1
TARBALL_SHA256= 7f360c9905849c3587d48efc0f0ecbc852c19f61a52b18530d6b005cb9148c57

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES = solaris-abi.patch 6724993.patch,-p1

# Since we're patching src/Makefile.am in solaris-abi.patch,
# we need to autoreconf
AUTORECONF=yes

# Override the libraries pkg-config returns, to exclude the unneeded libXau
MODULE_CONFIG_ENV = XPRINT_LIBS='-lX11 -lXext'

# Library name
LIBNAME=Xp

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=man/*.man
MODULE_STABILITY=Committed
LIB_MAN_SUFFIX=3xp



# pkg-config files that need to have -R added
FIX_PC_FILES=xp.pc.in

# Compatibility links from /usr/X11/lib to /usr/lib
MODULE_X11_LIBCOMPAT_LINKS = libXp.so libXp.so.1

include ../Makefile.inc
