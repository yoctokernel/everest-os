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
// | Last Modified:      November 15, 2023                                                                             |
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

void _cli(void)
{
    asm volatile ("cli");
}

/// @fn  _cpuid(struct proc_state *regs, uint32_t leaf)
/// Executes the <c>CPUID</c> processor-identification instruction with the <c>leaf</c> argument placed in <c>EAX</c>.
/// The <c>CPUID</c> instruction is used for determination of processor capabilities and features. Depending on the 
/// specific argument placed in <c>EAX</c> prior to execution, the <c>CPUID</c> instruction will return various elements
/// of information. These can range from vendor identification strings (<c>EAX = 00h</c>) to complex bitwise-encoded 
/// flags about instruction sets and processor caching capabilities. Intel has published an entire 128-page application 
/// note on this subject; for more information, see Intel Corporation (2012) AP-485.
///
/// There are obscure ways to test for the presence of the <c>CPUID</c> instruction prior to executing it, a practice 
/// which should always be performed when potentially executing an instruction for which hardware support is not 
/// explicitly known at runtime. However, all modern x86 CPUs support this instruction, and the few that do not (early 
/// model 486s and earlier) are too historical to be supported by most operating systems and the presence of 
/// <c>CPUID</c> can safely be assumed.
///
/// @param[out] regs a pointer to an instance of a processor state struct to store the output of <c>CPUID</c>.
/// @param[in]  leaf the argument supplied to the <c>CPUID</c> instruction
/// @see struct proc_state
void _cpuid(struct proc_state *regs, uint32_t leaf)
{
    uint64_t a = 0, b = 0, c = 0, d = 0;
    asm volatile (
        "xorq  %%rax, %%rax \n"
        "movq  %0,    %%rax \n"
        "cpuid              \n"
        : "=a" (a), "=b" (b), "=c" (c), "=d" (d)
        : "r" ((uint64_t) leaf) );
    regs->rax = a;
    regs->rbx = b;
    regs->rcx = c;
    regs->rdx = d;
}

/// @fn _inb(uint16_t port)
/// Reads and returns a byte value from the I/O bus location specified by <c>port</c>.
///
/// @param[in] port
/// @return
uint8_t _inb(uint16_t port)
{

}

/// @fn _inw(uint16_t port)
/// Reads and returns a word (16-bit) value from the I/O bus location specified by <c>port</c>.
///
/// @param[in] port
/// @return
uint16_t _inw(uint16_t port)
{

}

/// @fn _ind(uint16_t port)
/// Reads and returns a doubleword (32-bit) value from the I/O bus location specified by <c>port</c>.
///
/// @param[in] port
/// @return
uint32_t _ind(uint16_t port)
{

}

/// @fn  _rdtsc(void)
/// Reads the value of the x86 Time Stamp Counter (TSC) register (MSR 10h). Returns this value to the user as a 64-bit
/// integer. This function is tagged naked to avoid the generation of function prologues and epilogues to improve
/// accuracy when reading the TSC - both registers modified by <c>RDTSC</c> are volatile per the System V x86-64 ABI
/// and no framing occurs within.
/// @see
uint64_t _rdtsc(void)
{
    uint64_t tsc = 0;
    asm volatile (
        "rdtsc              \n"
        "shlq  $32,   %%rdx \n"
        "orq   %%rdx, %%rax \n"
        : "=a" (tsc) );
    return (tsc);
}