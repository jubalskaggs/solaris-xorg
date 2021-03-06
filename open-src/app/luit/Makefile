###############################################################################
#
# luit - character set encoding filter for terminal emulators like xterm
#
# Copyright (c) 2008, 2016, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=luit

# Version number (used in path names)
MODULE_VERSION=1.1.1

# Checksums for upstream tarball
TARBALL_MD5   = c4a3664e08e5a47c120ff9263ee2f20c
TARBALL_SHA1  = 3130c14d7267cecce0ba2280643844b48cca49b0
TARBALL_SHA256= 30b0e787cb07a0f504b70f1d6123930522111ce9d4276f6683a69b322b49c636

# Patches to apply to source after unpacking, in order
SOURCE_PATCHES += solaris-man.patch,-p1
SOURCE_PATCHES += 6824625.patch,-p1
SOURCE_PATCHES += 22177995.patch,-p1

# Need to rebuild configure after patching configure.ac in remove-zlib.patch
AUTORECONF=yes

# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=terminal/$(MODULE_NAME)
MODULE_PKGNAME_SET=yes

# Package classification (override default)
MODULE_PKGCLASS=Applications/System Utilities
MODULE_PKGCLASS_SET=yes

# ARC cases that covered this module
# PSARC/2008/100 luit
MODULE_ARC_CASES = PSARC/2008/100
# PSARC/2011/033 X11R7.6 application updates
MODULE_ARC_CASES += PSARC/2011/033

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=man/luit.man
MODULE_STABILITY=Uncommitted

# Need to link with libfontenc in server private directory
MODULE_LDFLAGS=$(X11_SERVERLIBS_LDFLAGS)

# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = luit

include ../Makefile.inc

