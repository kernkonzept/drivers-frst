/*
 * (c) 2016 Adam Lackorzynski <adam@l4re.org>
 *
 * This file is part of L4Re and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#pragma once

#include "uart_base.h"

namespace L4
{
  class Uart_sh : public Uart
  {
  public:
    explicit Uart_sh() {}
    bool startup(Io_register_block const *) override;
    void shutdown() override;
    bool enable_rx_irq(bool enable = true) override;
    bool change_mode(Transfer_mode m, Baud_rate r) override;
    void irq_ack() override;
    int get_char(bool blocking = true) const override;
    int char_avail() const override;
    int tx_avail() const;
    void wait_tx_done() const {}
    inline void out_char(char c) const;
    int write(char const *s, unsigned long count,
              bool blocking = true) const override;
  };
};
