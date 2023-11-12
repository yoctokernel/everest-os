// +-------------------------------------------------------------------------------------------------------------------+
// | File:               arch/msrs.h                                                                                   |
// | Title:              x86-64 (Intel 64/AMD64) Model-Specific Register (MSR) Address Definitions                     |
// | Project:            Everest OS (kernel)                                                                           |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides C/C++ preprocessor definitions for standard x86 (IA-32) and x86-64         |
// |                     model-specific register (MSR) addresses for use with the RDMSR and WRMSR instructions.        |
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

#ifndef MSRS_H
#define MSRS_H 

#define MSR_IA32_P5_MC_ADDR           0x00000000
#define MSR_IA32_P5_MC_TYPE           0x00000001
#define MSR_IA32_MONITOR_FILTER_SIZE  0x00000006
#define MSR_IA32_TIME_STAMP_COUNTER   0x00000010
#define MSR_IA32_PLATFORM_ID          0x00000017
#define MSR_IA32_APIC_BASE            0x0000001B
#define MSR_IA32_FEATURE_CONTROL      0x0000003A
#define MSR_IA32_TSC_ADJUST           0x0000003B
#define MSR_IA32_SPEC_CTRL            0x00000048
#define MSR_IA32_PRED_CMD             0x00000049
#define MSR_IA32_PPIN_CTL             0x0000004E
#define MSR_IA32_PPIN                 0x0000004F
#define MSR_IA32_BIOS_UPDT_TRIG       0x00000079
#define MSR_IA32_BIOS_SIGN_ID         0x0000008B
#define MSR_IA32_SGXLEPUBKEYHASH0     0x0000008C
#define MSR_IA32_SGXLEPUBKEYHASH1     0x0000008D
#define MSR_IA32_SGXLEPUBKEYHASH2     0x0000008E
#define MSR_IA32_SGXLEPUBKEYHASH3     0x0000008F
#define MSR_IA32_SMM_MONITOR_CTL      0x0000009B
#define MSR_IA32_SMBASE               0x0000009E
#define MSR_IA32_MISC_PACKAGE_CTLS    0x000000BC
#define MSR_IA32_XAPIC_DISABLE_STATUS 0x000000BD
#define MSR_IA32_PMC0                 0x000000C1
#define MSR_IA32_PMC1                 0x000000C2
#define MSR_IA32_PMC2                 0x000000C3
#define MSR_IA32_PMC3                 0x000000C4
#define MSR_IA32_PMC4                 0x000000C5
#define MSR_IA32_PMC5                 0x000000C6
#define MSR_IA32_PMC6                 0x000000C7
#define MSR_IA32_PMC7                 0x000000C8
#define MSR_IA32_CORE_CAPABILITIES    0x000000CF
#define MSR_IA32_UMWAIT_CONTROL       0x000000E1
#define MSR_IA32_MPERF                0x000000E7
/* Page 2-10, Intel SDM, Vol. 4 */

#endif /* MSRS_H */