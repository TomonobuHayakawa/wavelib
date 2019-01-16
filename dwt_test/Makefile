
-include $(TOPDIR)/Make.defs
-include $(SDKDIR)/Make.defs

MY_DIR = $(shell pwd)
APPTOP_DIR = $(MY_DIR)/..

CONFIG_WAVELIB_DWT_TEST_PRIORITY ?= SCHED_PRIORITY_DEFAULT
CONFIG_WAVELIB_DWT_TEST_STACKSIZE ?= 2048

APPNAME = dwt_test
PRIORITY = $(CONFIG_WAVELIB_DWT_TEST_PRIORITY)
STACKSIZE = $(CONFIG_WAVELIB_DWT_TEST_STACKSIZE)

# VPATH = $(MY_DIR))/auxiliary $(MY_DIR)/src

ASRCS =
CSRCS = ../auxiliary/waux.c ../auxiliary/denoise.c ../src/conv.c ../src/cwt.c ../src/cwtmath.c ../src/hsfft.c ../src/real.c ../src/wavefilt.c ../src/wavefunc.c ../src/wavelib.c ../src/wtmath.c
# CSRCS = waux.c denoise.c conv.c cwt.c cwtmath.c hsfft.c real.c wavefilt.c wavefunc.c wavelib.c wtmath.c
MAINSRC = dwt_test_main.c

CONFIG_WAVELIB_DWT_TEST_PROGNAME ?= dwt_test$(EXEEXT)
PROGNAME = $(CONFIG_WAVELIB_DWT_TEST_PROGNAME)

CFLAGS += -I $(APPTOP_DIR)$(DELIM)header
CFLAGS += -I $(APPTOP_DIR)$(DELIM)src
CFLAGS += -I $(APPTOP_DIR)$(DELIM)auxiliary
CXXFLAGS += -I $(APPTOP_DIR)$(DELIM)header
CXXFLAGS += -I $(APPTOP_DIR)$(DELIM)src
CXXFLAGS += -I $(APPTOP_DIR)$(DELIM)auxiliary

include $(APPDIR)/Application.mk


