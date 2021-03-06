#
# Copyright (c) 2015, 2016, Oracle and/or its affiliates. All rights reserved.
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
###############################################################################
#
#  This Makefile builds mdb modules.
#  It is designed to build both kernel kmdb and mdb .so files
#
###############################################################################


TOP:sh=hg root
KERNEL	= $(TOP)/open-src/kernel
BUILD_TYPE = 64
include $(TOP)/open-src/common/Makefile.init
# Need common defaults
include $(TOP)/open-src/common/Makefile.defs
include $(KERNEL)/Makefile.rules

KMOD	= i915
MDBMOD	= i915.so
MODULES	= $(KMOD) $(MDBMOD)

CFLAGS		+= -v -xdebugformat=stabs  -xildoff
CFLAGS		+= -std=c11
CFLAGS		+= -D_ELF64 -DMDB_DEBUG -D_KERNEL -D_KMDB -g -m64
CPPFLAGS	+= -I$(KERNEL)
CPPFLAGS	+= -I$(KERNEL)/sys/drm
CPPFLAGS	+= -I$(KERNEL)/sys
CPPFLAGS	+= -I$(PROTODIR)/usr/include
CPPFLAGS	+= -I$(PROTODIR)/usr/include/drm
CPPFLAGS	+= -I/usr/include
KMOD_LDFLAGS	= -ztype=kmod -znodefs -Nmisc/kmdbmod -Mmapfile
$(MDBMOD):= CFLAGS += -KPIC
$(KMOD):= CFLAGS += -xmodel=kernel
SO_LDFLAGS	= $(LDFLAGS) -Wl,-z,direct -Wl,-z,text -M mapfile
SO_LDFLAGS	+= -Wl,-z,parent=/usr/bin$(ARCHLIBSUBDIR)/mdb
CPPFLAGS	+= -xO3 -m64 -Ui386 -U__i386 -errtags=yes -errwarn=%all \
	-erroff=E_EMPTY_TRANSLATION_UNIT -erroff=E_STATEMENT_NOT_REACHED \
	-W0,-xglobalstatic -g -W0,-noglobal \
	-DTEXT_DOMAIN=\"SUNW_OST_OSCMD\" -D_ERRNO_VERIFY -DMDB_DEBUG \
	-D_KERNEL -D_ELF64

SOURCES		= i915.c
OBJECTS		= $(SOURCES:%.c=%.o)
LINTFILES	= $(SOURCES:%.c=%.ln)
BC_OBJS		= $(SOURCES:%.c=%.o.bc)

all: $(MODULES)

.KEEP_STATE:

.NO_PARALLEL:
.PARALLEL: $(OBJECTS) $(LINTFILES)

$(OBJECTS): $(SOURCES)
	@print CFLAGS=$(CFLAGS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
	$(CTFCONVERT) $(CTFCVTFLAGS) $@

$(KMOD): $(OBJECTS)
	$(LD) -o $@ $(OBJECTS) $(KMOD_LDFLAGS) $(LIBS)
	$(CTFMERGE) $(CTFMERGE_LABEL) -o $@ $(OBJECTS)

$(MDBMOD): $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -G -o $@ $(SOURCES) $(LDFLAGS) \
		$(SO_LDFLAGS) $(LIBS)

install: $(MODULES)
	@print Installing $(KMOD) in $(PROTODIR)$(ROOT_KMOD_DIR)
	@print Installing $(MDBMOD) in $(PROTODIR)$(ROOT_MDB_DIR)
	@mkdir -p $(PROTODIR)$(ROOT_KMOD_DIR)
	@mkdir -p $(PROTODIR)$(ROOT_MDB_DIR)
	@$(INSTALL_SCRIPT) -m 555 $(KMOD) $(PROTODIR)$(ROOT_KMOD_DIR)
	@$(INSTALL_SCRIPT) -m 555 $(MDBMOD) $(PROTODIR)$(ROOT_MDB_DIR)

clean:
	rm -f $(OBJECTS) $(BC_OBJS) $(MODULES)

clean.lint:
	rm -f $(LINTFILES)

clobber: clean clean.lint
	rm -f $(MODULES)

%.ln:%.c
	$(LINT) $(LINTFLAGS) $(CPPFLAGS) -o $@ $<

lint: $(LINTFILES)

