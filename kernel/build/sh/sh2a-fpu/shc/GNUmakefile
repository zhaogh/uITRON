# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# --------------------------------------
#  %jp{�e��ݒ�}%en{setting}
# --------------------------------------

# %jp{�^�[�Q�b�g���C�u������}%en{target library name}
TARGET ?= libhosv4a


# %jp{�A�[�L�e�N�`����`}%en{architecture}
ARCH_NAME ?= sh2a-fpu
ARCH_PROC ?= sh/sh2a-fpu
ARCH_IRC  ?= simple
ARCH_CC   ?= shc


# %jp{�f�B���N�g����`}%en{directories}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
INC_PROC_DIR      = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR       = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR      = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR   = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR       = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR    = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)
CFGRTR_DIR        = $(TOP_DIR)/cfgrtr/build/gcc


# %jp{�R���t�B�M�����[�^��`}%en{kernel configurator}
CFGRTR = h4acfg-$(ARCH_NAME)


# %jp{�J�[�l���w��}%en{kernel flag}
KERNEL = Yes


# %jp{���ʒ�`�Ǎ���}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{�p�X�ݒ�}%en{Source path}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{�I�v�V�����t���O}%en{compile options}
CFLAGS  += -CPu=sh2afpu
AFLAGS  += -CPu=sh2afpu
ARFLAGS += 


ifeq ($(FAST_VECTOR),Yes)
A_DEFS += _KERNEL_FAST_INTVEC="ON"
endif


# %jp{�R���p�C���ˑ��̐ݒ�Ǎ���}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{���C�u���������p�ݒ�Ǎ���}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{�\�[�X�t�@�C��}%en{source files}
# --------------------------------------

# %jp{C����t�@�C���̒ǉ�}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/clr_int.c
CSRCS += $(SRC_IRC_DIR)/get_imsk.c
CSRCS += $(SRC_IRC_DIR)/chg_imsk.c
CSRCS += $(SRC_IRC_DIR)/chg_ilv.c
CSRCS += $(SRC_IRC_DIR)/get_ilv.c

# %jp{�A�Z���u���t�@�C���̒ǉ�}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.src
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.src
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.src
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.src

# %jp{�J�[�l�����ʃ\�[�X�̒ǉ�}%en{kernel common sources}
include $(KERNEL_MAKINC_DIR)/knlsrc.inc




# --------------------------------------
#  %jp{���[����`}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{�N���[��}$en{clean}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst

# %jp{�ˑ��֌W�X�V}%en{make depend}
.PHONY : depend
clean: makelib_clean

# source file copy
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{���C�u���������p�ݒ�Ǎ���}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{�R���p�C���ˑ��̃��[����`�Ǎ���}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc


# --------------------------------------
#  %jp{�ˑ��֌W}%en{dependency}
# --------------------------------------

# %jp{�J�[�l���ˑ��֌W�Ǎ���}%en{dependence}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file