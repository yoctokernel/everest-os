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

#ifndef MSRS_H
#define MSRS_H 

#define MSR_IA32_P5_MC_ADDR              0x00000000
#define MSR_IA32_P5_MC_TYPE              0x00000001
#define MSR_IA32_MONITOR_FILTER_SIZE     0x00000006
#define MSR_IA32_TIME_STAMP_COUNTER      0x00000010
#define MSR_IA32_PLATFORM_ID             0x00000017
#define MSR_IA32_APIC_BASE               0x0000001B
#define MSR_IA32_FEATURE_CONTROL         0x0000003A
#define MSR_IA32_TSC_ADJUST              0x0000003B
#define MSR_IA32_SPEC_CTRL               0x00000048
#define MSR_IA32_PRED_CMD                0x00000049
#define MSR_IA32_PPIN_CTL                0x0000004E
#define MSR_IA32_PPIN                    0x0000004F
#define MSR_IA32_BIOS_UPDT_TRIG          0x00000079
#define MSR_IA32_BIOS_SIGN_ID            0x0000008B
#define MSR_IA32_SGXLEPUBKEYHASH0        0x0000008C
#define MSR_IA32_SGXLEPUBKEYHASH1        0x0000008D
#define MSR_IA32_SGXLEPUBKEYHASH2        0x0000008E
#define MSR_IA32_SGXLEPUBKEYHASH3        0x0000008F
#define MSR_IA32_SMM_MONITOR_CTL         0x0000009B
#define MSR_IA32_SMBASE                  0x0000009E
#define MSR_IA32_MISC_PACKAGE_CTLS       0x000000BC
#define MSR_IA32_XAPIC_DISABLE_STATUS    0x000000BD
#define MSR_IA32_PMC0                    0x000000C1
#define MSR_IA32_PMC1                    0x000000C2
#define MSR_IA32_PMC2                    0x000000C3
#define MSR_IA32_PMC3                    0x000000C4
#define MSR_IA32_PMC4                    0x000000C5
#define MSR_IA32_PMC5                    0x000000C6
#define MSR_IA32_PMC6                    0x000000C7
#define MSR_IA32_PMC7                    0x000000C8
#define MSR_IA32_CORE_CAPABILITIES       0x000000CF
#define MSR_IA32_UMWAIT_CONTROL          0x000000E1
#define MSR_IA32_MPERF                   0x000000E7
#define MSR_IA32_APERF                   0x000000E8
#define MSR_IA32_MTRRCAP                 0x000000FE
#define MSR_IA32_ARCH_CAPABILITIES       0x0000010A
#define MSR_IA32_FLUSH_CMD               0x0000010B
#define MSR_IA32_TSX_FORCE_ABORT         0x0000010F
#define MSR_IA32_TSX_CTRL                0x00000122
#define MSR_IA32_MCU_OPT_CTRL            0x00000123
#define MSR_IA32_SYSENTER_CS             0x00000174
#define MSR_IA32_SYSENTER_ESP            0x00000175
#define MSR_IA32_SYSENTER_EIP            0x00000176
#define MSR_IA32_MCG_CAP                 0x00000179
#define MSR_IA32_MCG_STATUS              0x0000017A
#define MSR_IA32_MCG_CTL                 0x0000017B
#define MSR_IA32_PERFEVTSEL0             0x00000186
#define MSR_IA32_PERFEVTSEL1             0x00000187
#define MSR_IA32_PERFEVTSEL2             0x00000188
#define MSR_IA32_PERFEVTSEL3             0x00000189
#define MSR_IA32_PERFEVTSEL4             0x0000018A
#define MSR_IA32_PERFEVTSEL5             0x0000018B
#define MSR_IA32_PERFEVTSEL6             0x0000018C
#define MSR_IA32_PERFEVTSEL7             0x0000018D
#define MSR_IA32_OVERCLOCKING_STATUS     0x00000195
#define MSR_IA32_PERF_STATUS             0x00000198
#define MSR_IA32_PERF_CTL                0x00000199
#define MSR_IA32_CLOCK_MODULATION        0x0000019A
#define MSR_IA32_THERM_INTERRUPT         0x0000019B
#define MSR_IA32_THERM_STATUS            0x0000019C
#define MSR_IA32_MISC_ENABLE             0x000001A0
#define MSR_IA32_ENERGY_PERF_BIAS        0x000001B0
#define MSR_IA32_PACKAGE_THERM_STATUS    0x000001B1
#define MSR_IA32_PACKAGE_THERM_INTERRUPT 0x000001B2
#define MSR_IA32_XFD                     0x000001C4
#define MSR_IA32_XFD_ERR                 0x000001C5
#define MSR_IA32_DEBUGCTL                0x000001D9
#define MSR_IA32_LER_FROM_IP             0x000001DD
#define MSR_IA32_LER_TO_IP               0x000001DE
#define MSR_IA32_LER_INFO                0x000001E0
#define MSR_IA32_SMRR_PHYSBASE           0x000001F2
#define MSR_IA32_SMRR_PHYSMASK           0x000001F3
#define MSR_IA32_PLATFORM_DCA_CAP        0x000001F8
#define MSR_IA32_CPU_DCA_CAP             0x000001F9
#define MSR_IA32_DCA_O_CAP               0x000001FA
#define MSR_IA32_MTRR_PHYSBASE0          0x00000200
#define MSR_IA32_MTRR_PHYSMASK0          0x00000201
#define MSR_IA32_MTRR_PHYSBASE1          0x00000202
#define MSR_IA32_MTRR_PHYSMASK1          0x00000203
#define MSR_IA32_MTRR_PHYSBASE2          0x00000204
#define MSR_IA32_MTRR_PHYSMASK2          0x00000205
#define MSR_IA32_MTRR_PHYSBASE3          0x00000206
#define MSR_IA32_MTRR_PHYSMASK3          0x00000207
#define MSR_IA32_MTRR_PHYSBASE4          0x00000208
#define MSR_IA32_MTRR_PHYSMASK4          0x00000209
#define MSR_IA32_MTRR_PHYSBASE5          0x0000020A
#define MSR_IA32_MTRR_PHYSMASK5          0x0000020B
#define MSR_IA32_MTRR_PHYSBASE6          0x0000020C
#define MSR_IA32_MTRR_PHYSMASK6          0x0000020D
#define MSR_IA32_MTRR_PHYSBASE7          0x0000020E
#define MSR_IA32_MTRR_PHYSMASK7          0x0000020F
#define MSR_IA32_MTRR_PHYSBASE8          0x00000210
#define MSR_IA32_MTRR_PHYSMASK8          0x00000211
#define MSR_IA32_MTRR_PHYSBASE9          0x00000212
#define MSR_IA32_MTRR_PHYSMASK9          0x00000213
#define MSR_IA32_MTRR_FIX64K_00000       0x00000250
#define MSR_IA32_MTRR_FIX16K_80000       0x00000258
#define MSR_IA32_MTRR_FIX16K_A0000       0x00000259
#define MSR_IA32_MTRR_FIX4K_C0000        0x00000268
#define MSR_IA32_MTRR_FIX4K_C8000        0x00000269
#define MSR_IA32_MTRR_FIX4K_D0000        0x0000026A
#define MSR_IA32_MTRR_FIX4K_D8000        0x0000026B
#define MSR_IA32_MTRR_FIX4K_E0000        0x0000026C
#define MSR_IA32_MTRR_FIX4K_E8000        0x0000026D
#define MSR_IA32_MTRR_FIX4K_F0000        0x0000026E
#define MSR_IA32_MTRR_FIX4K_F8000        0x0000026F
#define MSR_IA32_PAT                     0x00000277
#define MSR_IA32_MC0_CTL2                0x00000280
#define MSR_IA32_MC1_CTL2                0x00000281
#define MSR_IA32_MC2_CTL2                0x00000282
#define MSR_IA32_MC3_CTL2                0x00000283
#define MSR_IA32_MC4_CTL2                0x00000284
#define MSR_IA32_MC5_CTL2                0x00000285
#define MSR_IA32_MC6_CTL2                0x00000286
#define MSR_IA32_MC7_CTL2                0x00000287
#define MSR_IA32_MC8_CTL2                0x00000288
#define MSR_IA32_MC9_CTL2                0x00000289
#define MSR_IA32_MC10_CTL2               0x0000028A
#define MSR_IA32_MC11_CTL2               0x0000028B
#define MSR_IA32_MC12_CTL2               0x0000028C
#define MSR_IA32_MC13_CTL2               0x0000028D
#define MSR_IA32_MC14_CTL2               0x0000028E
#define MSR_IA32_MC15_CTL2               0x0000028F
#define MSR_IA32_MC16_CTL2               0x00000290
#define MSR_IA32_MC17_CTL2               0x00000291
#define MSR_IA32_MC18_CTL2               0x00000292
#define MSR_IA32_MC19_CTL2               0x00000293
#define MSR_IA32_MC20_CTL2               0x00000294
#define MSR_IA32_MC21_CTL2               0x00000295
#define MSR_IA32_MC22_CTL2               0x00000296
#define MSR_IA32_MC23_CTL2               0x00000297
#define MSR_IA32_MC24_CTL2               0x00000298
#define MSR_IA32_MC25_CTL2               0x00000299
#define MSR_IA32_MC26_CTL2               0x0000029A
#define MSR_IA32_MC27_CTL2               0x0000029B
#define MSR_IA32_MC28_CTL2               0x0000029C
#define MSR_IA32_MC29_CTL2               0x0000029D
#define MSR_IA32_MC30_CTL2               0x0000029E
#define MSR_IA32_MC31_CTL2               0x0000029F
#define MSR_IA32_MTRR_DEF_TYPE           0x000002FF
#define MSR_IA32_FIXED_CTR0              0x00000309
#define MSR_IA32_FIXED_CTR1              0x0000030A
#define MSR_IA32_FIXED_CTR2              0x0000030B
#define MSR_IA32_PERF_CAPABILITIES       0x00000345
#define MSR_IA32_FIXED_CTR_CTRL          0x0000038D
/* Page 2-32, Intel SDM, Vol. 4 */

#endif /* MSRS_H */