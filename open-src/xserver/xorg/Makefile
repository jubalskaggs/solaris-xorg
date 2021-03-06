###############################################################################
#
# Xorg server Makefile
#
# Copyright (c) 2006, 2017, Oracle and/or its affiliates. All rights reserved.
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
MODULE_NAME=xorg-server

# Package metadata
MODULE_DESC = portions of the X.Org X server software
GIT_URL     = $(XORG_GIT_URL)/xserver
GIT_URL_SET = yes

# Version number (used in path names) - set in open-src/common/Makefile.init
MODULE_VERSION=$(XORGSERVER_VERS)

# Checksums for upstream tarball
TARBALL_MD5   = 4ac6feeae6790436ce9de879ca9a3bf8
TARBALL_SHA1  = 307d3405f709f7e41966c850b37deefe7f83eb9b
TARBALL_SHA256= 18fffa8eb93d06d2800d06321fc0df4d357684d8d714315a66d8dfa7df251447

# Patches to apply to source after unpacking, in order
# *** Moved to patch-list file so they can be shared between Xorg & Xvnc builds
SOURCE_PATCHES=$(XORG_SOURCE_PATCHES)

# Used in rules shared between Xorg & Xvnc builds in Makefile.inc
# to allow for different source layouts
XORG_SOURCE_DIR=$(SOURCE_DIR)
XORG_BUILD_DIR=$(BUILD_DIR)

# ARC cases that covered this module
# PSARC/2004/187 Xorg Server for Solaris
MODULE_ARC_CASES = PSARC/2004/187
# PSARC/2004/685 Xorg server upgrade to X11R6.8 release
MODULE_ARC_CASES += PSARC/2004/685
# PSARC/2004/829 Xorg 6.8.2 server upgrade for Solaris
MODULE_ARC_CASES += PSARC/2004/829
# PSARC/2005/450 Xorg 6.9 for Solaris
MODULE_ARC_CASES += PSARC/2005/450
# PSARC/2006/609 Xserver provider for DTrace
MODULE_ARC_CASES += PSARC/2006/609
# PSARC/2007/051 Xorg server upgrade to 7.2
MODULE_ARC_CASES += PSARC/2007/051
# PSARC/2007/434 Xorg server 1.3
MODULE_ARC_CASES += PSARC/2007/434
# PSARC/2007/500 X11 MIT-SHM Extension across zones
MODULE_ARC_CASES += PSARC/2007/500
# PSARC/2008/294 Xorg driver selection based on VIS_GETIDENTIFIER
MODULE_ARC_CASES += PSARC/2008/294
# PSARC/2009/021 Xorg server 1.5
MODULE_ARC_CASES += PSARC/2009/021
# PSARC/2009/292 Xorg server 1.6
MODULE_ARC_CASES += PSARC/2009/292
# PSARC/2009/679 Xorg server 1.7
MODULE_ARC_CASES += PSARC/2009/679
# PSARC/2010/109 Introduce libXcb in Solaris
MODULE_ARC_CASES += PSARC/2010/109
# PSARC/2011/008 Xorg server 1.9
MODULE_ARC_CASES += PSARC/2011/008
# PSARC/2010/382 Removal of 32-bit X servers
MODULE_ARC_CASES += PSARC/2010/382
# PSARC/2011/214 Xorg server 1.10
MODULE_ARC_CASES += PSARC/2011/214
# PSARC/2012/144 Xorg server 1.12
MODULE_ARC_CASES += PSARC/2012/144
# PSARC/2012/320 Xorg server 1.13
MODULE_ARC_CASES += PSARC/2012/320
# PSARC/2013/091 Xorg server 1.14
MODULE_ARC_CASES += PSARC/2013/091
# PSARC/2015/251 Xorg server 1.17
MODULE_ARC_CASES += PSARC/2015/251
# PSARC/2016/293 Xorg server 1.18
MODULE_ARC_CASES += PSARC/2016/293
# PSARC/2017/212 Xorg server 1.19
MODULE_ARC_CASES += PSARC/2017/212

# Man pages to apply Sun footer to & attributes to list
SUNTOUCHED_MANPAGES= \
	man/Xserver.man \
	hw/dmx/config/man/xdmxconfig.man \
	hw/dmx/config/man/vdltodmx.man \
	hw/dmx/config/man/dmxtodmx.man \
	hw/dmx/man/Xdmx.man \
	hw/kdrive/ephyr/man/Xephyr.man \
	hw/xfree86/exa/man/exa.man \
	hw/xfree86/fbdevhw/man/fbdevhw.man \
	hw/xfree86/utils/man/cvt.man \
	hw/xfree86/utils/man/gtf.man \
	hw/xfree86/man/Xorg.man \
	hw/xfree86/man/xorg.conf.man \
	hw/xfree86/man/xorg.conf.d.man \
	hw/vfb/man/Xvfb.man

MODULE_STABILITY=Volatile

# Override specific attributes for specific man pages
MODULE_SUNTOUCH_MAN_FLAGS= \
	$(SUNTOUCH_MAN_FLAGS_$(@F:%.man.$(FIXED_MAN_SUFFIX)=%))
# Xephyr, Xvfb, and Xdmx are split out into their own packages
SUNTOUCH_MAN_FLAGS_Xephyr = -o '{Availability, $(MODULE_PKGNAME:%xorg=%xephyr)}'
SUNTOUCH_MAN_FLAGS_Xvfb = -o '{Availability, $(MODULE_PKGNAME:%xorg=%xvfb)}'
SUNTOUCH_MAN_FLAGS_Xdmx = -o '{Availability, $(MODULE_PKGNAME:%xorg=%xdmx)}'
SUNTOUCH_MAN_FLAGS_Xserver = -o '{Availability, $(MODULE_PKGNAME:%xorg=%xserver-common)}'
SUNTOUCH_MAN_FLAGS_cvt = -o '{Availability, x11/modeline-utilities}'
SUNTOUCH_MAN_FLAGS_gtf = -o '{Availability, x11/modeline-utilities}' 
SUNTOUCH_MAN_FLAGS_xdmxconfig = $(SUNTOUCH_MAN_FLAGS_Xdmx)
SUNTOUCH_MAN_FLAGS_vdltodmx = $(SUNTOUCH_MAN_FLAGS_Xdmx)
SUNTOUCH_MAN_FLAGS_dmxtodmx = $(SUNTOUCH_MAN_FLAGS_Xdmx)

# Binary built in tree
XORGSERVER_BIN=$(BUILD_DIR)/hw/xfree86/Xorg

BUILD_TARGETS=$(XORGSERVER_BIN) build_mdb set-elf-comments \
	$(BUILD_DIR)/mapfile-Xorg-externs
BUILD_TARGETS_SET=yes

# Need to regenerate autoconf/automake files after patching
AUTORECONF=yes

# Command line options to GNU autoconf configure script
# XXX: --disable-dga
MODULE_CONFIG_OPTS = $(XSERVER_CONFIG_OPTS) \
        --enable-dmx \
        --enable-builddocs \
	--enable-kdrive --enable-xephyr --disable-xsdl \
	--disable-systemd-logind \
	--disable-glamor \
	MKFONTDIR="$(MKFONTDIR)" \
	MKFONTSCALE="$(MKFONTSCALE)"

MODULE_LDFLAGS = $(XSERVER_LDFLAGS)
MODULE_LD_OPTIONS = $(MAPFILES_FOR_ALL)

# Pass linker mapfile listing symbols that modules can count on resolving
# from the Xorg binary itself
XORG_EXTERNS_FILE = mapfile-Xorg-externs.$(MACH)
XORG_EXTERNS_FLAG = -Wl,-M,$(PWD)/$(XORG_EXTERNS_FILE)
MODULE_BUILD_ENV = XORG_EXTERNS_FLAG='$(XORG_EXTERNS_FLAG)'
MODULE_LD_SHARED_OPTIONS += -M $(PWD)/$(XORG_EXTERNS_FILE)

# Disable direct binding in shared objects, since it breaks libglx.so
MODULE_BUILD_ENV += LD_SHARED_UNSET="-B direct"

# Optimization doesn't always remove unused inline functions, leaving many 
# binaries referencing pixman symbols that normally don't need them.  The
# $(ZDISCARD_UNUSED_DEP) in LD_OPTIONS should avoid adding it when
# not really needed.
MODULE_CONFIG_OPTS += LIBS="-lpixman-1"

# pkg-config files that need to have -R added
FIX_PC_FILES=xorg-server.pc.in
# Remove compiler specific visibility flag that breaks builds of drivers
# with other compilers
MODULE_FIX_PC_FLAGS= -e 's|\@symbol_visibility\@||'

# Need to use GNU Make to build due to hw/xfree86/loader
MODULE_MAKE=$(GNUMAKE)
MODULE_MAKE_SET=yes

# Additional configure time targets beyond the defaults
MODULE_ADD_CONFIGURE_TARGETS=clear_build_date

# Additional install targets beyond the defaults
MODULE_ADD_INSTALL_TARGETS=install_extras install_mdb install_pc_common \
	install_fix_paths install_docs

# Have to avoid dependency loop between install_pc_common and 
# install_pkgconfig_uninstalled
INSTALL_PCU_DEPS = $(INSTALL_TARGETS:install_pc_common=)
INSTALL_PCU_DEPS_SET=yes

# Merge in additional sources from sun-src directory
ADDITIONAL_SOURCE_DIR=sun-src

# Compatibility links from /usr/X11/bin to /usr/bin
# Only needed for programs that were in /usr/X11/bin before we moved
MODULE_X11_BINCOMPAT_LINKS = Xorg Xephyr Xvfb cvt gtf
MODULE_X11_BINCOMPAT_LINKS_i386 = amd64
MODULE_X11_BINCOMPAT_LINKS += $(MODULE_X11_BINCOMPAT_LINKS_$(MACH))

# Binaries that were linked to isaexec on x86 to choose 32-bit or 64-bit,
# now just symlinks from amd64 to parent directory
LINKED_TO_ISAEXEC = Xorg Xephyr Xvfb Xdmx

include ../Makefile.inc

# Don't include build date & time in delivered binaries as it just causes
# unnecessary binary differences to be pulled into package updates, but
# leave it in debug builds for developer convenience
$(BUILD_DEBUG:yes=$(POUND_SIGN)) CBD_TARGET = actually_clear_build_date

clear_build_date: $(CBD_TARGET)

actually_clear_build_date: $(AUTOCONF_TARGET)
	printf '#undef BUILD_DATE\n#undef BUILD_TIME\n' > \
		$(BUILD_DIR)/hw/xfree86/common/xf86Build.h

$(XORGSERVER_BIN): default_build

SDK_INCLUDES_DIR=$(PROTODIR)$(XORG_SDK_INCLUDES_DIR)

install_extras: default_install
	-rm -f $(SDK_INCLUDES_DIR)/xorg-server.h
	sed -e 's%#define XF86DRI 1%/* #define XF86DRI 1 */%' \
	    $(BUILD_DIR)/include/xorg-server.h > $(SDK_INCLUDES_DIR)/xorg-server.h
	cp -pf $(SOURCE_DIR)/mi/mioverlay.h \
	       $(SOURCE_DIR)/hw/xfree86/os-support/bus/xf86Sbus.h \
	       $(SOURCE_DIR)/hw/xfree86/dri/*.h $(SDK_INCLUDES_DIR)/
	mkdir -p $(PROTODIR)$(MODULE_MAN_DIR)/man1
	cp -pf $(SOURCE_DIR)/hw/xfree86/man/xorgcfg.1 \
	       $(SOURCE_DIR)/hw/xfree86/man/xorgconfig.1 \
	       $(PROTODIR)$(MODULE_MAN_DIR)/man1
	mkdir -p $(PROTODIR)/etc/hal/fdi/preprobe/10osvendor
	cp -pf $(SOURCE_DIR)/config/x11-input.fdi \
	 $(PROTODIR)/etc/hal/fdi/preprobe/10osvendor/10-x11-input.fdi
	mkdir -p $(PROTODIR)/etc/X11/xorg.conf.d \
		 $(PROTODIR)/etc/X11/xorg.conf.avail \
		 $(PROTODIR)/usr/share/X11/xorg.conf.d
	cp -pf 90-zap.conf $(PROTODIR)/etc/X11/xorg.conf.avail

# Workaround bug in installing pkgconfig file to wrong directory in 64-bit
# builds, and install xorg-server.pc in 32-bit pkgconfig dir too
install_pc_common: default_install install_pkgconfig_uninstalled 
	-rm -f $(PROTODIR)$(PKGCONFIG_DIR)/xorg-server.pc
	mkdir -p $(PROTODIR)$(PKGCONFIG_DIR)
	cp -pf $(BUILD_DIR)/xorg-server.pc \
		$(PROTODIR)$(PKGCONFIG_DIR)/xorg-server.pc
	-rm -f $(PROTODIR)$(PKGCONFIG_DIR_32)/xorg-server.pc \
		$(PROTODIR)$(PKGCONFIG_DIR_32)/xorg-server-uninstalled.pc
	mkdir -p $(PROTODIR)$(PKGCONFIG_DIR_32)
	ln -s ../$(SUBDIR64)$(PKGCONFIG_DIR_suffix)/xorg-server.pc \
	    ../$(SUBDIR64)$(PKGCONFIG_DIR_suffix)/xorg-server-uninstalled.pc \
		$(PROTODIR)$(PKGCONFIG_DIR_32)/

# Generate a list of exported functions & data objects so that we can verify
# loadable modules don't reference symbols that have been deleted or renamed.
SYMBOL_AWK_SCRIPT  = \
'BEGIN { print "\043 Functions exported by Xorg server to loadable modules" ; \
	 print "\n\044mapfile_version 2\n\nSYMBOL_SCOPE {\n\tglobal:" } \
 END   { print "};" } \
 $$7 ~ /UNDEF|\.tdata/  { next } \
 $$5 !~ /GLOB/  { next } \
 $$8 ~ /^(__|_edata|_end|_etext|_start|_environ|_lib_version)/ { next } \
 $$4 ~ /FUNC/ && $$7 ~ /\.text/ { printf "\t\t%-40s { FLAGS = EXTERN };\n", $$8 } \
 $$4 ~ /OBJT/ && $$7 ~ /data|bss/ { printf "\t\t%-40s { FLAGS = EXTERN };\n", $$8}'

$(BUILD_DIR)/mapfile-Xorg-externs: $(XORGSERVER_BIN)
	-rm -f $@
	LC_ALL=C /usr/bin/nm -gs $(XORGSERVER_BIN) | \
	    gawk -F\| $(SYMBOL_AWK_SCRIPT) > $@
#	cmp $(XORG_EXTERNS_FILE) $@

# Fix paths in proto area to match paths in packages / installed systems
install_fix_paths_X: default_install
	rm -f $(PROTODIR)$(MODULE_BIN_DIR)/X \
	      $(PROTODIR)$(MODULE_BIN_DIR)/$(ARCHBINSUBDIR)/X
	ln -s Xserver $(PROTODIR)$(MODULE_BIN_DIR)/X

install_fix_paths: install_fix_paths_X

MESA_MODULE_DIR = /usr/lib/mesa/modules/extensions
EXT_MODULE_DIR = $(X11_SERVERMODS_DIR)/extensions

install_fix_paths_glxmodule: default_install
	@rm -f $(PROTODIR)$(MESA_MODULE_DIR)/libglx.so
	mkdir -p $(PROTODIR)$(MESA_MODULE_DIR)/
	mv -f $(PROTODIR)$(EXT_MODULE_DIR)/libglx.so \
	      $(PROTODIR)$(MESA_MODULE_DIR)/libglx.so
	ln -s ../../../../../system/volatile/opengl/server/libglx.so \
	      $(PROTODIR)$(EXT_MODULE_DIR)/libglx.so

install_fix_paths: install_fix_paths_glxmodule

# Install metadata for Xephyr, Xvfb, & Xdmx packages too
XCOMMON_PKG_METADATA_DIR = $(MODULE_PKG_METADATA_DIR:%-xorg=%-xserver-common)
XEPHYR_PKG_METADATA_DIR = $(MODULE_PKG_METADATA_DIR:%-xorg=%-xephyr)
XVFB_PKG_METADATA_DIR =	  $(MODULE_PKG_METADATA_DIR:%-xorg=%-xvfb)
XDMX_PKG_METADATA_DIR =	  $(MODULE_PKG_METADATA_DIR:%-xorg=%-xdmx)
MODES_PKG_METADATA_DIR = $(MODULE_PKG_METADATA_DIR:%-server-xorg=%-modeline-utilities)

EXTRA_METADATA_DIRS =	$(XCOMMON_PKG_METADATA_DIR) \
			$(XEPHYR_PKG_METADATA_DIR) \
			$(XVFB_PKG_METADATA_DIR) \
			$(XDMX_PKG_METADATA_DIR) \
			$(MODES_PKG_METADATA_DIR)

EXTRA_ATTRDATA_FILES = $(EXTRA_METADATA_DIRS:%=%/$(ATTRDATA_FILE_NAME))
EXTRA_LICENSE_FILES =  $(EXTRA_METADATA_DIRS:%=%/$(LICENSE_FILE_NAME))

EXTRA_METADATA_TARGETS=	$(EXTRA_METADATA_DIRS) \
			$(EXTRA_ATTRDATA_FILES) \
			$(EXTRA_LICENSE_FILES)

install_metadata: $(EXTRA_METADATA_TARGETS)

$(EXTRA_ATTRDATA_FILES) $(EXTRA_LICENSE_FILES): $(EXTRA_METADATA_DIRS)

$(EXTRA_METADATA_DIRS):
	mkdir -p $@

# Special compatibility links from /usr/X11/include to /usr/include
X11_INCLUDE_COMPAT_DIR = $(PROTODIR)/usr/X11/include
X11_INCLUDE_COMPAT_LINKS = $(X11_INCLUDE_COMPAT_DIR)/drm \
	$(X11_INCLUDE_COMPAT_DIR)/xorg

install: $(X11_INCLUDE_COMPAT_LINKS)

$(X11_INCLUDE_COMPAT_DIR):
	mkdir -p $@

$(X11_INCLUDE_COMPAT_LINKS): $(X11_INCLUDE_COMPAT_DIR)
	@rm -f $@
	ln -s ../../include/$(@F) $@

## mdb module rules
# Build & install mdb modules & scripts that aren't integrated to
# normal build process.
MDB_SOURCE_DIR = $(XORG_SOURCE_DIR)/os/solaris/mdb
MDB_BUILD_DIR  =  $(XORG_BUILD_DIR)/os/solaris/mdb
MDB_REL_SOURCE_DIR = ../../../../$(MDB_SOURCE_DIR)
MDB_MODULE_DIR=/usr/lib/mdb/proc/$(ARCHLIBSUBDIR)
MDB_SCRIPT_DIR=/usr/demo/Xserver/mdb
MDB_SCRIPTS=list_Xserver_clients \
	list_Xserver_devicegrab_client \
	list_Xserver_servergrab_client
MDB_MODULE_NAMES=Xephyr Xorg Xvfb Xvnc Xdmx

BUILT_MDB_MODULE=$(MDB_BUILD_DIR)/modules/Xserver.so
BUILT_MDB_SCRIPTS=$(MDB_SCRIPTS:%=$(MDB_BUILD_DIR)/scripts/%)

INSTALLED_MDB_LINKS=$(MDB_MODULE_NAMES:%=$(PROTODIR)$(MDB_MODULE_DIR)/%.so)
INSTALLED_MDB_MODULE=$(PROTODIR)$(MDB_MODULE_DIR)/Xserver.so
INSTALLED_MDB_SCRIPTS=$(MDB_SCRIPTS:%=$(PROTODIR)$(MDB_SCRIPT_DIR)/%)
INSTALLED_MDB_ALL=$(INSTALLED_MDB_MODULE) $(INSTALLED_MDB_LINKS) \
	$(INSTALLED_MDB_SCRIPTS)

# Since configure options aren't used to build the mdb modules, pass
# those variables at build time
MDB_BUILD_ENV=$(CONFIG_ENV) $(BUILD_ENV)
MDB_BUILD_ENV += CFLAGS="$(LIB_CFLAGS)" LDFLAGS="$(LIB_LDFLAGS)"
MDB_BUILD_ENV += ARCHLIBSUBDIR="$(ARCHLIBSUBDIR)"
MDB_BUILD_ENV += top_builddir="$(PWD)/$(BUILD_DIR)"
MDB_BUILD_ENV += top_srcdir="$(PWD)/$(SOURCE_DIR)"

build_mdb: $(BUILT_MDB_MODULE)

$(BUILT_MDB_SCRIPTS): $(SOURCE_TARGETS)

$(MDB_BUILD_DIR): $(SOURCE_TARGETS) $(BUILD_DIR) $(LNDIR)
	mkdir -p $(MDB_BUILD_DIR)
	cd $(MDB_BUILD_DIR) && $(LNDIR) $(MDB_REL_SOURCE_DIR)

$(BUILT_MDB_MODULE): $(CONFIGURE_TARGETS) $(MDB_BUILD_DIR)
	(cd $(MDB_BUILD_DIR) && \
         $(MDB_BUILD_ENV) $(MAKE) $(MAKEFLAGS) $(DEFAULT_BUILD_MAKEFLAGS))

$(PROTODIR)$(MDB_MODULE_DIR) $(PROTODIR)$(MDB_SCRIPT_DIR):
	mkdir -p $@

$(INSTALLED_MDB_MODULE): $(PROTODIR)$(MDB_MODULE_DIR) $(BUILT_MDB_MODULE)
	$(INSTALL_SCRIPT) -c -m 0555 $(BUILT_MDB_MODULE) $@

$(INSTALLED_MDB_LINKS): $(PROTODIR)$(MDB_MODULE_DIR)
	@rm -f $@
	ln -s Xserver.so $@

$(INSTALLED_MDB_SCRIPTS): $(BUILT_MDB_SCRIPTS) $(PROTODIR)$(MDB_SCRIPT_DIR)
	$(INSTALL_SCRIPT) -c -m 0555 $(MDB_SOURCE_DIR)/scripts/$(@F) \
		$(PROTODIR)$(MDB_SCRIPT_DIR)/

install_mdb: $(INSTALLED_MDB_ALL)
	$(INSTALL_SCRIPT) -c -m 0444 $(MDB_SOURCE_DIR)/README \
		$(PROTODIR)$(MDB_SCRIPT_DIR)/

## Backwards compatibility for old doc path
INSTALLED_DOC_LINK = $(PROTODIR)$(MODULE_DOC_DIR:$(MODULE_NAME)=Xserver)

## IPS package release notes shown when upgrading
$(PROTODIR)$(RELNOTES_DIR):
	mkdir -p $@

install_docs: $(PROTODIR)$(RELNOTES_DIR) $(INSTALLED_DOC_LINK)
	$(INSTALL_SCRIPT) -c -m 0444 release-notes/*.txt \
		$(PROTODIR)$(RELNOTES_DIR)

$(INSTALLED_DOC_LINK): $(PROTODIR)$(MODULE_DOC_DIR)
	@rm -f $@
	ln -s $(MODULE_NAME) $@
