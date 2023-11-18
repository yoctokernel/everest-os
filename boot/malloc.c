// +-------------------------------------------------------------------------------------------------------------------+
// | File:               boot/malloc.c                                                                                 |
// | Title:              UEFI Bootloader Helper Functions (Memory Allocation Components)                               |
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

/// @fn      *malloc(size_t)
/// This function wraps the EFI native <c>BootServices->AllocatePool()</c> function to provide a more user-friendly 
/// memory allocation interface. This function allocates <c>size</c> bytes of memory under the UEFI <c>EfiLoaderData</c>
/// class. Similar to the C standard library versions of <c>*malloc()</c>, this function returns <c>NULL</c> if, for any
/// reason, the memory allocation request fails.
/// @param   size the number of bytes of memory to allocate
/// @return       a pointer to the allocated memory block
void *malloc(size_t size) 
{
    void *ptr;
    EFI_STATUS alloc_status = BS->AllocatePool(EfiLoaderData, (UINTN) size, &ptr);
    if (EFI_ERROR(alloc_status))
        return NULL;
    else
        return ptr;
}

/// @fn     memset(void *restrict, size_t, uint8_t)
/// Performs a bytewise copy of a particular value into an allocated memory region. Note that this function is not a 
/// part of any memory allocation system; as such, it has no ability to check whether or not a memory region exists, is
/// properly allocated, or whether <c>length</c> fits within the region specified. This function also does not represent
/// the most optimal solution to fast setting of arbitrary memory sizes, and is mainly intended for quick-and-dirty 
/// zeroing of allocated pools.
/// @param  buf    the allocated buffer to copy to
/// @param  length the size of the buffer to iterate over and set to value
/// @param  value  the repeating byte value to copy into the buffer
/// @return        the actual number of bytes copied
size_t memset(void *restrict buf, size_t length, uint8_t value)
{
    size_t copied  = 0;
    uint8_t  val8  = value;
    uint16_t val16 = ((uint16_t) val8)  <<  8 | ((uint16_t) val8);
    uint32_t val32 = ((uint32_t) val16) << 16 | ((uint16_t) val16);
    uint64_t val64 = ((uint64_t) val32) << 32 | ((uint64_t) val32);
    if (length % 8 == 0) {
        for (size_t k = 0; k < length / 8; k++) {
            ptr[k] = val64;
            copied += 8;
        }
    }
    else if (length % 4 == 0) {
        for (size_t k = 0; k < length / 4; k++) {
            ptr[k] = val32;
            copied += 4;
        }
    }
    else if (length % 2 == 0) {
        for (size_t k = 0; k < length / 2; k++) {
            ptr[k] = val16;
            copied += 2;
        }
    }
    else {
        for (size_t k = 0; k < length; k++) {
            ptr[k] = val8;
            copied++;
        }
    }
    return copied;
}

/// @fn     *calloc(size_t, size_t)
/// This function is used to allocate and zero a memory region for use with data structures. Similar to the C standard
/// library implementation of this function, this function accepts two arguments: a <c>count</c> or <c>nmemb</c> 
/// parameter which specifies the number of members of space to allocate, followed by a <c>size</c> parameter indicating
/// the size of each member in bytes. Similarly to @ref *malloc(size_t), this function returns a <c>NULL</c> pointer if
/// the allocation fails for any reason.
/// @see    *malloc(size_t), memset(void *restrict, size_t, uint8_t)
/// @param  count the number of members to allocate
/// @param  size  the size of each member in bytes
/// @return       a pointer to the allocated and zeroed memory buffer
void *calloc(size_t count, size_t size)
{
    size_t total_size = count * size;
    void *ptr;
    EFI_STATUS alloc_status = BS->AllocatePool(EfiLoaderData, (UINTN) total_size, &ptr);
    if (EFI_ERROR(alloc_status))
        return NULL;
    if (memset(ptr, total_size, 0x00) != total_size)
        return NULL;
    else
        return ptr;
}

/// @fn    free(void *)
/// Frees a memory allocation provided by <c>malloc()</c> or <c>calloc()</c>. Sets the library-static <c>EFI_STATUS</c>
/// with the state of the deallocation process.
/// @see   *malloc(size_t), *calloc(size_t, size_t)
/// @param ptr 
void free(void *ptr)
{
    _status = BS->FreePool(ptr);
}