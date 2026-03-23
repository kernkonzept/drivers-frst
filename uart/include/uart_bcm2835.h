/*
 * Copyright (C) 2026 Kernkonzept GmbH.
 * Author(s): Jakub Jermar <jakub.jermar@kernkonzept.com>
 *
 * License: see LICENSE.spdx (in this directory or the directories above)
 */

#pragma once

#include "uart_16550.h"

namespace L4 {

/*
 * According to the BCM2835 ARM Peripherals document, the mini UART is not
 * compatible with the 16550 UART, but has a 16550-like register layout.
 * The document is known to have many errors, including the mini UART part, as
 * described in this errata:
 *
 *   https://elinux.org/BCM2835_datasheet_errata#p12
 *
 * Even from the errata the meaning of some bits in the IER is not very clear.
 */
class Uart_bcm2835 : public Uart_16550
{
public:
  explicit Uart_bcm2835(unsigned long base_rate)
  : Uart_16550(base_rate, 0, 8)
  {}
};

} // namespace L4
