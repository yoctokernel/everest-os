// +-------------------------------------------------------------------------------------------------------------------+
// | File:               boot/env.c                                                                                    |
// | Title:              UEFI Bootloader Helper Functions (Environment Components)                                     |
// | Project:            Everest OS (Bootloader)                                                                       |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides implementations of UEFI helper functions related to configuring the boot   |
// |                     services environment.                                                                         |
// | License:            3-Clause ("New") BSD                                                                          |
// | Created:            November 17, 2023                                                                             |
// | Last Modified:      November 17, 2023                                                                             |
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

#include "uefi.h"

/// @fn    init(EFI_HANDLE handle, EFI_SYSTEM_TABLE *table)
/// @param handle 
/// @param table 
void init(EFI_HANDLE handle, EFI_SYSTEM_TABLE *table)
{
    IH = handle;
    ST = table;
    BS = ST->BootServices;
    CT = ST->ConfigurationTable;
}

/// @fn    exit(void)
/// Calls the <c>ExitBootServices(EFI_HANDLE ImageHandle, UINTN MapKey)</c> function used to terminate EFI boot services
/// and hand control to the operating system. Note that this function <b>must</b> be called with a valid <c>MapKey</c> 
/// reference to a constructed memory map.
void exit(void)
{
    _status = BS->ExitBootServices(IH, MapKey);
}