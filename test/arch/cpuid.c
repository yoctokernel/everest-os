// +-------------------------------------------------------------------------------------------------------------------+
// | File:               test/arch/cpuid.c                                                                             |
// | Title:              CPUID Function Test Code                                                                      |
// | Project:            Everest OS (Kernel) Tests                                                                     |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file tests the CPUID instruction wrapper provided in <arch/primitives.h>.                |
// | License:            3-Clause ("New") BSD                                                                          |
// | Created:            November 16, 2023                                                                             |
// | Last Modified:      November 16, 2023                                                                             |
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

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

struct proc_state {
    uint64_t rax;    ///< general purpose A register
    uint64_t rbx;    ///< general purpose B register
    uint64_t rcx;    ///< general purpose C register
    uint64_t rdx;    ///< general purpose D register
    uint64_t rsi;    ///< the source index register
    uint64_t rdi;    ///< the destination index register
    uint64_t rbp;    ///< the frame pointer register
    uint64_t rsp;    ///< the stack pointer register
    uint64_t r8;     ///< the R8 (64-bit extension) register
    uint64_t r9;     ///< the R9 (64-bit extension) register
    uint64_t r10;    ///< the R10 (64-bit extension) register
    uint64_t r11;    ///< the R11 (64-bit extension) register
    uint64_t r12;    ///< the R12 (64-bit extension) register
    uint64_t r13;    ///< the R13 (64-bit extension) register
    uint64_t r14;    ///< the R14 (64-bit extension) register
    uint64_t r15;    ///< the R15 (64-bit extension) register
    uint64_t rflags; ///< the processor state register 
};

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

int main(int argc, char **argv)
{
    struct proc_state proc;
    _cpuid(&proc, 0);
    printf("EAX = %X, EBX = %X, ECX = %X, EDX = %X\n",
    (uint32_t) proc.rax, (uint32_t) proc.rbx, (uint32_t) proc.rcx, (uint32_t) proc.rdx
    );
    return 0;
}