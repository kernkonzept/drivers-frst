/*
 * Copyright (C) 2021, 2024 Kernkonzept GmbH.
 * Author(s): Jakub Jermar <jakub.jermar@kernkonzept.com>
 *
 * License: see LICENSE.spdx (in this directory or the directories above)
 */

#pragma once

#include <l4/sys/l4int.h>

namespace Asm_access {

inline
l4_uint8_t
read(l4_uint8_t const *mem)
{
  l4_uint8_t val;

  asm volatile ("ldrb %w[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint16_t
read(l4_uint16_t const *mem)
{
  l4_uint16_t val;

  asm volatile ("ldrh %w[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint32_t
read(l4_uint32_t const *mem)
{
  l4_uint32_t val;

  asm volatile ("ldr %w[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
l4_uint64_t
read(l4_uint64_t const *mem)
{
  l4_uint64_t val;

  asm volatile ("ldr %[val], %[mem]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
void
write(l4_uint8_t val, l4_uint8_t *mem)
{
  asm volatile ("strb %w[val], %[mem]" :[mem]  "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint16_t val, l4_uint16_t *mem)
{
  asm volatile ("strh %w[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint32_t val, l4_uint32_t *mem)
{
  asm volatile ("str %w[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

inline
void
write(l4_uint64_t val, l4_uint64_t *mem)
{
  asm volatile ("str %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

}
