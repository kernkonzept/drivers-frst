/*
 * (c) 2017 Adam Lackorzynski <adam@l4re.org>
 *
 * This file is part of L4Re and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#include "uart_mvebu.h"
#include "poll_timeout_counter.h"

namespace L4
{
  enum
  {
    // use names from manual
    RBR  = 0x00,
    TSH  = 0x04,
    CTRL = 0x08,
    STAT = 0x0c,
    BRDV = 0x10,

    STAT_RX_RDY       = 0x0010,
    STAT_TXFIFO_FULL  = 0x0800,

    CTRL_RX_RDY_INT_EN = 1 <<  4,
    CTRL_RXFIFO_RST    = 1 << 14,
    CTRL_TXFIFO_RST    = 1 << 15,
  };

  bool Uart_mvebu::startup(Io_register_block const *regs)
  {
    _regs = regs;

    regs->write<unsigned>(CTRL, CTRL_RXFIFO_RST | CTRL_TXFIFO_RST);
    regs->write<unsigned>(CTRL, 0);

    return true;
  }

  bool Uart_mvebu::enable_rx_irq(bool enable)
  {
    if (enable)
      _regs->set<unsigned>(CTRL, CTRL_RX_RDY_INT_EN);
    else
      _regs->clear<unsigned>(CTRL, CTRL_RX_RDY_INT_EN);
    return true;
  }

  void Uart_mvebu::shutdown()
  {
    //_regs->write<unsigned>(CTRL, 0);
  }

  bool Uart_mvebu::change_mode(Transfer_mode, Baud_rate r)
  {
    _regs->write<unsigned>(BRDV, _baserate / r / 16);
    return true;
  }

  int Uart_mvebu::get_char(bool blocking) const
  {
    while (!char_avail())
      if (!blocking)
        return -1;

    return _regs->read<unsigned>(RBR) & 0xff;
  }

  int Uart_mvebu::char_avail() const
  {
    return _regs->read<unsigned>(STAT) & STAT_RX_RDY;
  }

  void Uart_mvebu::out_char(char c) const
  {
    Poll_timeout_counter i(3000000);
    while (i.test(_regs->read<unsigned>(STAT) & STAT_TXFIFO_FULL))
      ;

    _regs->write<unsigned>(TSH, c);
    //_regs->clear<unsigned short>(SCFSR, SR_TEND | SR_TDFE);
  }

  int Uart_mvebu::write(char const *s, unsigned long count) const
  {
    unsigned long c = count;
    while (c--)
      out_char(*s++);

    return count;
  }
}
