
-include $(TOPDIR)/Make.defs
-include $(SDKDIR)/Make.defs

MY_DIR = $(shell pwd)

CONFIG_WAVELIB_DWT_TEST_PRIORITY ?= SCHED_PRIORITY_DEFAULT
CONFIG_WAVELIB_DWT_TEST_STACKSIZE ?= 2048

APPNAME = dwt_test
PRIORITY = $(CONFIG_WAVELIB_DWT_TEST_PRIORITY)
STACKSIZE = $(CONFIG_WAVELIB_DWT_TEST_STACKSIZE)

ASRCS =
CSRCS = auxiliary/waux.c auxiliary/denoise.c src/conv.c src/cwt.c src/cwtmath.c src/hsfft.c src/real.c src/wavefilt.c src/wavefunc.c src/wavelib.c src/wtmath.c
MAINSRC = dwt_test_main.c

CONFIG_WAVELIB_DWT_TEST_PROGNAME ?= dwt_test$(EXEEXT)
PROGNAME = $(CONFIG_WAVELIB_DWT_TEST_PROGNAME)

CFLAGS += -I $(MY_DIR)$(DELIM)header
CFLAGS += -I $(MY_DIR)$(DELIM)src
CFLAGS += -I $(MY_DIR)$(DELIM)auxiliary
CXXFLAGS += -I $(MY_DIR)$(DELIM)header
CXXFLAGS += -I $(MY_DIR)$(DELIM)src
CXXFLAGS += -I $(MY_DIR)$(DELIM)auxiliary

include $(APPDIR)/Application.mk


