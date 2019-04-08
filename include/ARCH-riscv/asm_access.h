/* SPDX-License-Identifier: GPL-2.0-only or License-Ref-kk-custom */
/*
 * Copyright (C) 2021 Kernkonzept GmbH.
 * Author(s): Georg Kotheimer <georg.kotheimer@kernkonzept.com>
 */

#pragma once

#include <l4/sys/l4int.h>

namespace Asm_access {

inline
l4_uint8_t
read(l4_uint8_t const *mem)
{
  l4_uint8_t val;

  asm volatile ("lb %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint16_t
read(l4_uint16_t const *mem)
{
  l4_uint16_t val;

  asm volatile ("lh %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint32_t
read(l4_uint32_t const *mem)
{
  l4_uint32_t val;

  asm volatile ("lw %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
void
write(l4_uint8_t val, l4_uint8_t *mem)
{
  asm volatile ("sb %[val], %[mem]" :[mem]  "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint16_t val, l4_uint16_t *mem)
{
  asm volatile ("sh %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint32_t val, l4_uint32_t *mem)
{
  asm volatile ("sw %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

#if __riscv_xlen == 64

inline
l4_uint64_t
read(l4_uint64_t const *mem)
{
  l4_uint64_t val;

  asm volatile ("ld %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
void
write(l4_uint64_t val, l4_uint64_t *mem)
{
  asm volatile ("sd %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

#endif

}
