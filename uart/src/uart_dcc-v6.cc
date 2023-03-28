/*
 * (c) 2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#include "uart_dcc-v6.h"

namespace L4
{
  bool Uart_dcc_v6::startup(Io_register_block const *)
  { return true; }

  void Uart_dcc_v6::shutdown()
  {}

  bool Uart_dcc_v6::change_mode(Transfer_mode, Baud_rate)
  { return true; }

  int Uart_dcc_v6::get_char(bool /*blocking*/) const
  {
#ifdef ARCH_arm
    int c;
    asm volatile("mrc p14, 0, %0, c0, c5, 0": "=r" (c));
    return c & 0xff;
#else
    return 0;
#endif
  }

  int Uart_dcc_v6::char_avail() const
  {
#ifdef ARCH_arm
    unsigned long s;
    asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (s));
    return s & 0x40000000;
#else
    return false;
#endif
  }

  void Uart_dcc_v6::out_char(char c) const
  {
#ifdef ARCH_arm
    unsigned long s;
    do
      asm volatile("mrc p14, 0, %0, c0, c1, 0" : "=r" (s));
    while (s & 0x20000000);
    asm volatile("mcr p14, 0, %0, c0, c5, 0": : "r" (c & 0xff));
#else
    (void)c;
#endif
  }

  int Uart_dcc_v6::write(char const *s, unsigned long count) const
  {
    unsigned long c = count;
    while (c--)
      out_char(*s++);
    return count;
  }
};
