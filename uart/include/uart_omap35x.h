/*
 * (c) 2009 Adam Lackorzynski <adam@os.inf.tu-dresden.de>
 *     economic rights: Technische Universität Dresden (Germany)
 *
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#ifndef L4_CXX_UART_OMAP35X_H__
#define L4_CXX_UART_OMAP35X_H__

#include "uart_base.h"

namespace L4
{
  class Uart_omap35x : public Uart
  {
  public:
    bool startup(Io_register_block const *) override;
    void shutdown() override;
    bool change_mode(Transfer_mode m, Baud_rate r) override;
    bool enable_rx_irq(bool) override;
    int get_char(bool blocking = true) const override;
    int char_avail() const override;
    inline void out_char(char c) const;
    int write(char const *s, unsigned long count) const override;
  };
};

#endif
