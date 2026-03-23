/*
 * Copyright (C) 2026 Kernkonzept GmbH.
 * Author(s): Jakub Jermar <jakub.jermar@kernkonzept.com>
 *
 * License: see LICENSE.spdx (in this directory or the directories above)
 */

/*!
 * \file   uart_bcm2835.cc
 * \brief  BCM2835 UART implementation
 */
#include "uart_bcm2835.h"

static l4re_device_spec_dt_ids dt_ids[] = {
  { .compatible = "brcm,bcm2835-aux-uart" },
  {},
};

l4re_register_device_uart_dt(L4::Uart_bcm2835, bcm2835, dt_ids);
