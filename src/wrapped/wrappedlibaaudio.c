// SPDX-License-Identifier: MIT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <dlfcn.h>
#include <stdint.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x64emu.h"
#include "emu/x64emu_private.h"
#include "callback.h"
#include "librarian.h"
#include "box64context.h"
#include "myalign.h"

const char* libaaudioName = "libaaudio.so";
#define LIBNAME libaaudio

#define ADDED_FUNCTIONS()                   \

#include "generated/wrappedlibaaudiotypes.h"

#include "wrappercallback.h"

// utility functions
#define SUPER() \
GO(0)   \
GO(1)   \
GO(2)   \
GO(3)

// AAudioStream_dataCallback returns AAUDIO_CALLBACK_RESULT_*, so the thunk has
// to hand that value back to AAudio, otherwise the stream stops immediately
#define GO(A)   \
static uintptr_t my_dataCallback_fct_##A = 0;                                           \
static int32_t my_dataCallback_##A(void* stream, void* userdata, void* data, int32_t frames) \
{                                                                                       \
    return (int32_t)RunFunctionFmt(my_dataCallback_fct_##A, "pppi", stream, userdata, data, frames); \
}
SUPER()
#undef GO
static void* find_dataCallback_Fct(void* fct)
{
    if(!fct) return NULL;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_dataCallback_fct_##A == (uintptr_t)fct) return my_dataCallback_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_dataCallback_fct_##A == 0) {my_dataCallback_fct_##A = (uintptr_t)fct; return my_dataCallback_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for libaaudio dataCallback callback\n");
    return NULL;
}

// AAudioStream_errorCallback
#define GO(A)   \
static uintptr_t my_errorCallback_fct_##A = 0;                                  \
static void my_errorCallback_##A(void* stream, void* userdata, int32_t error)   \
{                                                                               \
    RunFunctionFmt(my_errorCallback_fct_##A, "ppi", stream, userdata, error);   \
}
SUPER()
#undef GO
static void* find_errorCallback_Fct(void* fct)
{
    if(!fct) return NULL;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_errorCallback_fct_##A == (uintptr_t)fct) return my_errorCallback_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_errorCallback_fct_##A == 0) {my_errorCallback_fct_##A = (uintptr_t)fct; return my_errorCallback_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for libaaudio errorCallback callback\n");
    return NULL;
}

#undef SUPER

EXPORT void my_AAudioStreamBuilder_setDataCallback(x64emu_t* emu, void* builder, void* callback, void* userdata)
{
    my->AAudioStreamBuilder_setDataCallback(builder, find_dataCallback_Fct(callback), userdata);
}

EXPORT void my_AAudioStreamBuilder_setErrorCallback(x64emu_t* emu, void* builder, void* callback, void* userdata)
{
    my->AAudioStreamBuilder_setErrorCallback(builder, find_errorCallback_Fct(callback), userdata);
}

#include "wrappedlib_init.h"
