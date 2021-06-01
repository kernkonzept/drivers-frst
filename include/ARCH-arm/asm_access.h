/* SPDX-License-Identifier: GPL-2.0-only or License-Ref-kk-custom */
/*
 * Copyright (C) 2021 Kernkonzept GmbH.
 * Author(s): Jakub Jermar <jakub.jermar@kernkonzept.com>
 */

#pragma once

#include <l4/sys/l4int.h>

namespace Asm_access {

inline
l4_uint8_t
read(l4_uint8_t const *mem)
{
  l4_uint8_t val;

  asm volatile ("ldrb %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint16_t
read(l4_uint16_t const *mem)
{
  l4_uint16_t val;

  asm volatile ("ldrh %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint32_t
read(l4_uint32_t const *mem)
{
  l4_uint32_t val;

  asm volatile ("ldr %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
void
write(l4_uint8_t val, l4_uint8_t *mem)
{
  asm volatile ("strb %[val], %[mem]" :[mem]  "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint16_t val, l4_uint16_t *mem)
{
  asm volatile ("strh %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint32_t val, l4_uint32_t *mem)
{
  asm volatile ("str %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

}
