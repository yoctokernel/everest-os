// +-------------------------------------------------------------------------------------------------------------------+
// | File:               arch/primitives.h                                                                             |
// | Title:              x86-64 (Intel 64/AMD64) Instruction Primitives & Architectural Structures                     |
// | Project:            Everest OS (kernel)                                                                           |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides C/C++ macros for certain specialized x86 instructions (CPUID, RDMSR, etc.) |
// |                     for which compiler support may be poor. It also defines certain architectural structures, such|
// |                     as the 64-bit versions of descriptor tables.                                                  |
// | License:            3-Clause ("New") BSD                                                                          |
// | Created:            November 11, 2023                                                                             |
// | Last Modified:      November 12, 2023                                                                             |
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

#include <cstdalign>
#include <cstdarg>
#include <cstdint>
#include <cstddef>
#include <climits>

#include "arch/msrs.h"

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#ifdef __cplusplus
extern "C" {
#endif

/// @struct proc_state
/// Represents a complete snapshot of the processor's general-purpose register state when in x86-64 mode.
/// This structure is used by functions such as @ref _cpuid to avoid having to convolve registers in other ways.
/// @see    _cpuid
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

/// @struct gdt_entry
/// Provides a definition of a x86-64 Global Descriptor Table (GDT) entry. These entries are used to define the 
/// behavior of protected memory segments when operating in segmentation-based memory models. For x86-64, segmentation
/// is entirely deprecated; a minimum of six GDT entries (one null, four for userland/kernel code & data, and one for
/// the "System Segment") are required for the purpose of properly initializing Long Mode and bypassing legacy limit
/// check hardware, but otherwise are completely unused. The GDT can contain up to 8,192 entries.
/// @see    _lgdt, _sgdt
struct gdt_entry {
    uint16_t limit_lower;  ///< lower 16 bits of the segment limit (size)
    uint16_t base_lower;   ///< lower 16 bits of the segment base
    uint8_t  base_inner_0; ///< lower-middle 8 bits of the segment base
    uint8_t  access;       ///< access settings and GDT segment properties
    uint8_t  flags_limit;  ///< upper nibble provides additional access flags; lower nibble is upper 4 bits of limit
    uint8_t  base_inner_1; ///< upper-middle 8 bits of the segment base
    uint32_t base_upper;   ///< upper 32 bits of the segment base
    uint32_t reserved;     ///< reserved field used to pad out GDT entry to 16 bytes
} __attribute__((packed));

/// @struct idt_entry 
/// Provides a definition of a x86-64 Interrupt Descriptor Table (IDT). The IDT is ordinarily configured as a 256-entry
/// table whose offset fields correspond to addresses of interrupt handlers; upon receiving an interrupt, the 
/// appropriate IDT entry is pulled and validated (P bit, DPL, etc.) If these checks resolve, the CPU will continue 
/// the interrupt response process at the offset address encoded within the entry. 
///
/// It is important to note that, unlike the GDT, the IDT is much less flexible, as its presence and proper setup is 
/// absolutely critical to proper interrupt functionality. The CPU reports faults and exceptions (such as #UD and #GP)
/// through the interrupt mechanism, so failure to provide an appropriately-configured IDT will result in core reset.
/// Because of this, it is crucial that an IDT provide handlers for at least the first 32 interrupt vectors (00h to 1Fh,
/// which correspond to the architectural exception reservations). Similarly, more than 256 interrupt descriptors may be
/// furnished, but the CPU will only acknowledge vectors 00h to FFh.
/// @see    _lidt, _sidt
struct idt_entry {
    uint16_t offset_lower;     ///< lower 16 bits of the offset (call address)
    uint16_t segment_selector; ///< GDT selector; must match a valid/present GDT code entry
    uint16_t access;           ///< access settings and state bits for the interrupt vector entry
    uint16_t offset_inner;     ///< inner 16 bits of the offset (call address)
    uint32_t offset_upper;     ///< upper 32 bits of the offset (call address)
    uint32_t reserved;         ///< reserved field used to pad out IDT entry to 16 bytes
} __attribute__((packed));

/// @struct idt_ptr
/// Provides a convenient C/C++ structure for receiving results from the SIDT (Store Interrupt Descriptor Table 
/// Register) instruction. The \ref _sidt function declared below will adjust the \ref idt_ptr.size field appropriately.
/// @see    idt_entry, _sidt
struct idt_ptr {
    uint16_t          size;  ///< size of the table
    struct idt_entry *table; ///< pointer to IDT (table)
} __attribute__((packed));

void     _cpuid  (struct proc_state *regs, uint32_t leaf);
void     _lgdt   (struct gdt_entry *gdt, size_t table_size);
void     _lidt   (struct idt_entry *idt, size_t table_size);
void     _sgdt   (struct gdt_ptr *gdtr);
void     _sidt   (struct idt_ptr *idtr);
uint64_t _rdmsr  (uint32_t msr);
uint64_t _rdtsc  (void);
void     _wrmsr  (uint32_t msr, uint64_t val);
void     _syscall(struct proc_state *regs);
void     _swapgs (void) __attribute__((naked));

#ifdef __cplusplus
}
#endif 

#endif