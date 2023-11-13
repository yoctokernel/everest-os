// +-------------------------------------------------------------------------------------------------------------------+
// | File:               arch/primitives.c                                                                             |
// | Title:              x86-64 (Intel 64/AMD64) Instruction Primitives & Architectural Structures                     |
// | Project:            Everest OS (kernel)                                                                           |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides implementations of the x86 instruction macros as defined in the            |
// |                     arch/primitives.h header.                                                                     |
// | License:            3-Clause ("New") BSD                                                                          |
// | Created:            November 13, 2023                                                                             |
// | Last Modified:      November 13, 2023                                                                             |
// +-------------------------------------------------------------------------------------------------------------------+
// | Copyright (c) 2023 Elijah Creed Fedele (ecfedele@proton.me)                                                       |
// | All rights reserved.                                                                                              |
// |                                                                                                                   |
// | Redistribution and use in source and binary forms, with or without modification, are permitted provided that the  |
// | following conditions are met:                                                                                     |
// |                                                                                                                   |
// |   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the       |
// |      following disclaimer.                                                                                        |
// |   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the    |
// |      following disclaimer in the documentation and/or other materials provided with the distribution.             |
// |   3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote |
// |      products derived from this software without specific prior written permission.                               |
// |                                                                                                                   |
// | THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,| 
// | INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE | 
// | DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,|
// | SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   |
// | SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, |
// | WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  |
// | USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                          |
// +-------------------------------------------------------------------------------------------------------------------+

#include "arch/primitives.h"

/// @fn  _rdtsc(void)
/// Reads the value of the x86 Time Stamp Counter (TSC) register (MSR 10h). Returns this value to the user as a 64-bit
/// integer. This function is tagged naked to avoid the generation of function prologues and epilogues to improve
/// accuracy when reading the TSC - both registers modified by <c>RDTSC</c> are volatile per the System V x86-64 ABI
/// and no framing occurs within.
/// @see
uint64_t _rdtsc(void) __attribute__((naked))
{
	uint64_t tsc = 0;
	asm volatile (
		"rdtsc              \n"
		"shlq  %%rdx, $32   \n"
		"orq   %%rdx, %%rax \n"
		: "=a" (tsc) );
	return (tsc);
}