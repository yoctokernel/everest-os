// +-------------------------------------------------------------------------------------------------------------------+
// | File:               boot/uefi.h                                                                                   |
// | Title:              UEFI Bootloader Helper Functions                                                              |
// | Project:            Everest OS (Bootloader)                                                                       |
// | Version:            ---                                                                                           |
// | Main Author:        Elijah Creed Fedele (ecfedele@proton.me)                                                      |
// | Other Contributors: see CONTRIBUTORS.md                                                                           |
// | Description:        This file provides definitions of various UEFI helper functions for the Everest bootloader.   |
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

#ifndef UEFI_H
#define UEFI_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <efi.h>
#include <efilib.h>

#define EFI_ACPI_TABLE_GUID    {0x8868E871,0xE4F1,0x11D3,{0xBC,0x22,0x00,0x80,0xC7,0x3C,0x88,0x81}}
#define ACPI_TABLE_GUID        {0xEB9D2D30,0x2D88,0x11D3,{0x9A,0x16,0x00,0x90,0x27,0x3F,0xC1,0x4D}}
#define ACPI_10_TABLE_GUID     ACPI_TABLE_GUID
#define EFI_ACPI_20_TABLE_GUID EFI_ACPI_TABLE_GUID

static EFI_STATUS               _Status;
static EFI_HANDLE               _Image;
static EFI_SYSTEM_TABLE        *_SystemTable;
static EFI_BOOT_SERVICES       *_BootServices;
static EFI_CONFIGURATION_TABLE *_ConfigTable;

void    init   (EFI_HANDLE handle, EFI_SYSTEM_TABLE *table);
void   *malloc (size_t size);
void   *calloc (size_t count, size_t size);
void    free   (void *ptr);
void   *memcpy (void *restrict dest, const void *restrict src, size_t count);
void   *memfill(void *restrict dest, uint8_t rep, size_t count);
int     strchr (const char *str, const char chr, size_t index);
size_t  strcnt (const char *str, const char chr);
size_t  strlen (const char *str);
size_t  printf (const char *fmt, ...);
void    exit   ();

#endif /* UEFI_H */