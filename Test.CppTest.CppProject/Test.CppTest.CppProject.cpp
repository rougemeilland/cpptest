/*
Test.CppTest.CppProject.cpp

Copyright (c) 2017 Palmtree Software

This software is released under the MIT License.
https://opensource.org/licenses/MIT
*/

// CPUIDについて:
//   http://www.wdic.org/w/SCI/cpuid%20%28x86%29
// 組み込み関数について:
//   https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=Other // 本家(英語)
//   https://msdn.microsoft.com/ja-jp/library/hh977023.aspx // MS

#include "stdafx.h"
#include <intrin.h>
#include <immintrin.h>


// 組み込み関数の練習
extern "C"
{
    unsigned __int64 __stdcall _UM_Mul64_Emuration(unsigned __int64 x, unsigned __int64 y, unsigned __int64 * high_part)
    {
        unsigned __int32 xl = (unsigned __int32)x;
        unsigned __int32 xh = (unsigned __int32)(x >> 32);
        unsigned __int32 yl = (unsigned __int32)y;
        unsigned __int32 yh = (unsigned __int32)(y >> 32);
        unsigned __int64 m0 = (unsigned __int64)xl * yl;
        unsigned __int64 m1 = (unsigned __int64)xl * yh;
        unsigned __int64 m2 = (unsigned __int64)xh * yl;
        unsigned __int64 m3 = (unsigned __int64)xh * yh;

        unsigned __int32 r0 = (unsigned __int32)m0;
        unsigned __int32 r1 = (unsigned __int32)(m0 >> 32);
        unsigned __int32 r2 = (unsigned __int32)m3;
        unsigned __int32 r3 = (unsigned __int32)(m3 >> 32);
        if (_addcarry_u32(_addcarry_u32(0, r1, (unsigned __int32)m1, &r1), r2, (unsigned __int32)(m1 >> 32), &r2))
            ++r3;
        if (_addcarry_u32(_addcarry_u32(0, r1, (unsigned __int32)m2, &r1), r2, (unsigned __int32)(m2 >> 32), &r2))
            ++r3;
        *high_part = ((unsigned __int64)r3 << 32) | r2;
        return (((unsigned __int64)r1 << 32) | r0);
    }

#ifdef _IX64
    unsigned __int64 __stdcall  _UM_Mul64_Intrinsics(unsigned __int64 x, unsigned __int64 y, unsigned __int64 * high_part)
    {
        return (_umul128(x, y, high_part));
    }
#endif

    static unsigned __int64(__stdcall *_UM_EntryPoint_Mul64)(unsigned __int64 x, unsigned __int64 y, unsigned __int64* high_part) = _UM_Mul64_Emuration;

    __declspec(dllexport) int __stdcall UM_Initialize()
    {
#ifdef _IX86
        _UM_EntryPoint_Mul64 = _UM_Mul64_Emuration;
        return (TRUE);
#elif defined(_IX64)
        int cpu_id_buffer[4];
        __cpuid(cpu_id_buffer, 0);
        if (cpu_id_buffer[0] < 7)
            _UM_EntryPoint_Mul64 = _UM_Mul64_Emuration;
        else
        {
            __cpuid(cpu_id_buffer, 7);
            if (cpu_id_buffer[1] & 0x00000010)
                _UM_EntryPoint_Mul64 = _UM_Mul64_Intrinsics;
            else
                _UM_EntryPoint_Mul64 = _UM_Mul64_Emuration;
        }
        return (TRUE);
#elif
        return (FALSE);
#endif
    }

    __declspec(dllexport) int __stdcall UM_Add(int x, int y)
    {
        return (x + y);
    }

    __declspec(dllexport) unsigned __int64 __stdcall UM_Mul64(unsigned __int64 x, unsigned __int64 y, unsigned __int64* high_part)
    {
        return (*_UM_EntryPoint_Mul64)(x, y, high_part);
    }

}