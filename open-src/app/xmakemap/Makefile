###############################################################################
#
# xmakemap script to generate xmodmap files from current keyboard settings
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

MODULE_NAME=xmakemap

# pkg(5) name we deliver the files in (override default)
MODULE_PKGNAME=x11/x11-server-utilities
MODULE_PKGNAME_SET=yes

# Package metadata
MODULE_DESC = the xmakemap script to generate xmodmap files
MODULE_LICENSE = Oracle
MODULE_LICENSE_SET = yes

# Dates to show in Oracle copyright notice in pkg license file
# Earliest & latest of the copyrights in the Oracle files in this pkg
ORACLE_COPYRIGHT_YEARS = 1992, 2011

# No upstream sources for these files, since they're Sun created
MODULE_VERSION=src
SOURCE_TARBALL_NAME=NONE
SOURCE_TARBALL_NAME_SET=yes
ADDITIONAL_SOURCE_DIR=sun-src

# Don't need default targets for configure, build, or install, since there's
# nothing to build, and the install rule follows here
CONFIGURE_TARGETS = 
CONFIGURE_TARGETS_SET=yes
BUILD_TARGETS = 
BUILD_TARGETS_SET=yes
INSTALL_TARGETS = install_xmakemap
INSTALL_TARGETS_SET=yes

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES=*.man
MODULE_STABILITY=Committed

### Include common rulesets
# Compatibility links from /usr/X11/bin to /usr/bin
MODULE_X11_BINCOMPAT_LINKS = xmakemap

include ../Makefile.inc

DESTDIR=$(PROTODIR)

install_xmakemap: $(SOURCE_TARGETS) $(INSTALL_DEPS)
	mkdir -p $(DESTDIR)$(MODULE_BIN_DIR) \
		$(DESTDIR)$(MODULE_MAN_DIR)/man1
	$(INSTALL_SCRIPT) -m 0555 $(SOURCE_DIR)/xmakemap \
		$(DESTDIR)$(MODULE_BIN_DIR)
	$(INSTALL_SCRIPT) -m 0444 $(SOURCE_DIR)/xmakemap.man \
		$(DESTDIR)$(MODULE_MAN_DIR)/man1/xmakemap.1

