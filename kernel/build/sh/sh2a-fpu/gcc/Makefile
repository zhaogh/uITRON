# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2
#
# Copyright (C) 1998-2010 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= sh-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= sh2a-fpu
ARCH_PROC ?= sh/sh2a-fpu
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc


# %jp{ディレクトリ定義}%en{directories}
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


# %jp{コンフィギュレータ定義}%en{kernel configurator}
CFGRTR = h4acfg-$(ARCH_NAME)


# %jp{カーネル指定}%en{kernel flag}
KERNEL = Yes


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{ベクタの高速化}%en{fast vector}
ifeq ($(FAST_VECTOR),Yes)
A_DEFS += _KERNEL_FAST_INTVEC="ON"
endif


# %jp{オプションフラグ}
AFLAGS  = -m2a
CFLAGS  = -m2a
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_IRC_DIR)/chg_ilv.c
CSRCS += $(SRC_IRC_DIR)/chg_imsk.c
CSRCS += $(SRC_IRC_DIR)/clr_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/get_ilv.c
CSRCS += $(SRC_IRC_DIR)/get_imsk.c


# %jp{カーネル共通ソースの追加}%en{kernel common sources}
include $(KERNEL_MAKINC_DIR)/knlsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst

# %jp{依存関係更新}%en{make depend}
.PHONY : depend
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}{dependency list of kernel sources}
include $(KERNEL_MAKINC_DIR)/knldep.inc


$(OBJS_DIR)/val_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/chg_ilv.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/clr_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/dis_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/ena_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/get_ilv.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/chg_imsk.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/get_imsk.$(EXT_OBJ)	:	$(COMMON_HEADERS)



# end of file
