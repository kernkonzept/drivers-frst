/*
 * Copyright (C) 2021, 2024 Kernkonzept GmbH.
 * Author(s): Jakub Jermar <jakub.jermar@kernkonzept.com>
 *
 * License: see LICENSE.spdx (in this directory or the directories above)
 */

#pragma once

#include <l4/sys/l4int.h>
#include <x86/l4/drivers/asm_access.h>

namespace Asm_access {

inline
l4_uint64_t
read(l4_uint64_t const *mem)
{
  l4_uint64_t val;

  asm volatile ("movq %[mem], %[val]" : [val] "=r" (val) : [mem] "m" (*mem));

  return val;
}

inline
void
write(l4_uint64_t val, l4_uint64_t *mem)
{
  asm volatile ("movq %[val], %[mem]" : [mem] "=m" (*mem) : [val] "r" (val));
}

}
