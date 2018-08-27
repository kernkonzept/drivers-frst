/*
 * (c) 2017 Adam Lackorzynski <adam@l4re.org>
 *
 * This file is part of L4Re and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#pragma once

#include "uart_base.h"

namespace L4
{
  class Uart_mvebu : public Uart
  {
  public:
    explicit Uart_mvebu(unsigned baserate) : _baserate(baserate) {}
    bool startup(Io_register_block const *);
    void shutdown();
    bool enable_rx_irq(bool enable = true);
    bool change_mode(Transfer_mode m, Baud_rate r);
    int get_char(bool blocking = true) const;
    int char_avail() const;
    void out_char(char c) const;
    int write(char const *s, unsigned long count) const;
  private:
    unsigned _baserate;
  };
};
