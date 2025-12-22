PKGDIR         ?= ../..
L4DIR          ?= $(PKGDIR)/../..

SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_PL011)     += uart_pl011.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_SA1000)    += uart_sa1000.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_8250)      += uart_16550.cc uart_16550_dw.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_OMAP35X)   += uart_omap35x.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_IMX)       += uart_imx.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_S3C2410)   += uart_s3c2410.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_OF)        += uart_of.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_LEON3)     += uart_leon3.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_CADENCE)   += uart_cadence.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_ARM_DCC)   += uart_dcc-v6.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_SH)        += uart_sh.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_MVEBU)     += uart_mvebu.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_LINFLEX)   += uart_linflex.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_LPUART)    += uart_lpuart.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_DM)        += uart_dm.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_GENI)      += uart_geni.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_ABP)       += uart_apb.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_TEGRA_TCU) += uart_tegra-tcu.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_SBI)       += uart_sbi.cc
SRC_CC-$(CONFIG_DRIVERS_FRST_UART_DRV_SIFIVE)    += uart_sifive.cc
SYSTEMS         = $(SYSTEMS_PLAIN)
TARGET          = libdrivers_uart.a libdrivers_uart.p.a
PC_FILENAME     = drivers_uart

PRIVATE_INCDIR += $(SRC_DIR)/../include $(SRC_DIR)/../../include

INCLUDE_MAKE_RULES = $(SRC_DIR)/*/Make.rules

include $(L4DIR)/mk/lib.mk

CXXFLAGS += -fno-exceptions -fno-rtti
CXXFLAGS_arm64  += -mstrict-align

