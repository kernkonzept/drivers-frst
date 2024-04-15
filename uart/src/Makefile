PKGDIR         ?= ../..
L4DIR          ?= $(PKGDIR)/../..

SRC_CC-riscv   := uart_sbi.cc
SRC_CC         += uart_pl011.cc uart_sa1000.cc \
                  uart_16550.cc uart_omap35x.cc uart_imx.cc \
                  uart_s3c2410.cc uart_of.cc uart_leon3.cc \
                  uart_cadence.cc uart_dcc-v6.cc uart_16550_dw.cc \
                  uart_sh.cc uart_mvebu.cc uart_linflex.cc uart_lpuart.cc \
                  uart_dm.cc uart_geni.cc uart_apb.cc \
                  $(SRC_CC-$(ARCH))
SYSTEMS         = $(SYSTEMS_PLAIN)
TARGET          = libdrivers_uart.a libdrivers_uart.p.a
PC_FILENAME     = drivers_uart

PRIVATE_INCDIR += $(SRC_DIR)/../include $(SRC_DIR)/../../include

INCLUDE_MAKE_RULES = $(SRC_DIR)/*/Make.rules

include $(L4DIR)/mk/lib.mk

CXXFLAGS += -DL4_NO_RTTI -fno-exceptions -fno-rtti
CXXFLAGS_arm64  += -mstrict-align

