// +-------------------------------------------------------------------------------------------------------------------+
// | File:               arch/io.h                                                                                     |
// | Title:              x86-64 (Intel 64/AMD64) Model-Specific Register (MSR) Address Definitions                     |
// | Project:            Everest OS (kernel)                                                                           |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides C/C++ preprocessor definitions for standard x86 (IA-32) and x86-64         |
// |                     I/O ports, which are commonly used by legacy hardware.                                        |
// | License:            3-Clause ("New") BSD                                                                          |
// | Created:            November 14, 2023                                                                             |
// | Last Modified:      November 14, 2023                                                                             |
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

#ifndef IO_H
#define IO_H

#define PORT_8237_CH0_BASE_ADDR  0x0000
#define PORT_8237_CH0_WORD_COUNT 0x0001
#define PORT_8237_CH1_BASE_ADDR  0x0002
#define PORT_8237_CH1_WORD_COUNT 0x0003
#define PORT_8237_CH2_BASE_ADDR  0x0004
#define PORT_8237_CH2_WORD_COUNT 0x0005
#define PORT_8237_CH3_BASE_ADDR  0x0006
#define PORT_8237_CH3_WORD_COUNT 0x0007
#define PORT_8237_CH03_STATCOM   0x0008
#define PORT_8237_CH03_WRITEREQ  0x0009
#define PORT_8237_CH03_MASK      0x000A
#define PORT_8237_CH03_MODE      0x000B
#define PORT_8237_CH03_CLRBYTE   0x000C
#define PORT_8237_CH03_RESET     0x000D
#define PORT_8237_CH03_CLRMASK   0x000E
#define PORT_8237_CH03_WRITEMASK 0x000F

#define PORT_8259_PRI_COMMAND    0x0020
#define PORT_8259_PRI_DATA       0x0021

#define PORT_8254_CH0_DATA       0x0040
#define PORT_8254_CH1_DATA       0x0041
#define PORT_8254_CH2_DATA       0x0042
#define PORT_8254_MODE_CMD       0x0043

#define PORT_8259_SEC_COMMAND    0x00A0
#define PORT_8259_SEC_DATA       0x00A1

#define PORT_8237_CH4_BASE_ADDR  0x00C0
#define PORT_8237_CH4_WORD_COUNT 0x00C2
#define PORT_8237_CH5_BASE_ADDR  0x00C4
#define PORT_8237_CH5_WORD_COUNT 0x00C6
#define PORT_8237_CH6_BASE_ADDR  0x00C8
#define PORT_8237_CH6_WORD_COUNT 0x00CA
#define PORT_8237_CH7_BASE_ADDR  0x00CC
#define PORT_8237_CH7_WORD_COUNT 0x00CE
#define PORT_8237_CH47_STATCOM   0x00D0
#define PORT_8237_CH47_WRITEREQ  0x00D2
#define PORT_8237_CH47_MASK      0x00D4
#define PORT_8237_CH47_MODE      0x00D6
#define PORT_8237_CH47_CLRBYTE   0x00D8
#define PORT_8237_CH47_RESET     0x00DA
#define PORT_8237_CH47_CLRMASK   0x00DC
#define PORT_8237_CH47_WRITEMASK 0x00DE

#endif /* IO_H */