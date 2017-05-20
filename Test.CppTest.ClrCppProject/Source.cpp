// Test.CppTest.CppProject.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

// CPUIDについて:
//   http://www.wdic.org/w/SCI/cpuid%20%28x86%29
// 組み込み関数について:
//   https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=Other // 本家(英語)
//   https://msdn.microsoft.com/ja-jp/library/hh977023.aspx // MS

#include <windows.h>
#include <malloc.h>
#include <intrin.h>
#include <immintrin.h>

/*
unsigned __int64 _byteswap_uint64(_In_ unsigned __int64) // バイトオーダー変換(64bit)
unsigned long _byteswap_ulong(_In_ unsigned long) // バイトオーダー変換(32bit)
unsigned short _byteswap_ushort(_In_ unsigned short) // バイトオーダー変換(16bit)

void __movsb(unsigned char *, unsigned char const *, size_t) // メモリ移動(8bit)
void __movsw(unsigned short *, unsigned short const *, size_t) // メモリ移動(16bit)
void __movsd(unsigned long *, unsigned long const *, size_t) // メモリ移動(32bit)

void __stosb(unsigned char *, unsigned char, size_t) // メモリ設定(8bit)
void __stosw(unsigned short *, unsigned short, size_t) // メモリ設定(16bit)
void __stosd(unsigned long *, unsigned long, size_t) // メモリ設定(32bit)

unsigned char _addcarry_u8(unsigned char, unsigned char, unsigned char, unsigned char *) // 8ビット符号なし整数のキャリー付加算
unsigned char _addcarry_u16(unsigned char, unsigned short, unsigned short, unsigned short *) // 16ビット符号なし整数のキャリー付加算
unsigned char _addcarry_u32(unsigned char, unsigned int, unsigned int, unsigned int *) // 32ビット符号なし整数のキャリー付加算

unsigned char _subborrow_u8(unsigned char, unsigned char, unsigned char, unsigned char *) // 8ビット符号なし整数のボロー付減算
unsigned char _subborrow_u16(unsigned char, unsigned short, unsigned short, unsigned short *) // 8ビット符号なし整数のボロー付減算
unsigned char _subborrow_u32(unsigned char, unsigned int, unsigned int, unsigned int *) // 8ビット符号なし整数のボロー付減算

__int64 __emul(int, int) // 符号付乗算(32bit * 32bit => 64bit)
unsigned __int64 __emulu(unsigned int, unsigned int) // 符号なし乗算(32bit * 32bit => 64bit)

unsigned char _BitScanForward(unsigned long * _Index, unsigned long _Mask) // LSBからMSBに向かってビット1を検索する
unsigned char _BitScanReverse(unsigned long * _Index, unsigned long _Mask) // MSBからLSBに向かってビット1を検索する

unsigned char _rotl8(unsigned char _Value, unsigned char _Shift) // 8ビット整数の左ローテート
unsigned short _rotl16(unsigned short _Value, unsigned char _Shift) // 16ビット整数の左ローテート
unsigned int _rotl(_In_ unsigned int _Value, _In_ int _Shift) // 32ビット整数の左ローテート
unsigned __int64 _rotl64(_In_ unsigned __int64 _Value, _In_ int _Shift) // 64ビット整数の左ローテート

unsigned char _rotr8(unsigned char _Value, unsigned char _Shift) // 8ビット整数の左ローテート
unsigned short _rotr16(unsigned short _Value, unsigned char _Shift) // 16ビット整数の左ローテート
unsigned int _rotr(_In_ unsigned int _Value, _In_ int _Shift) // ビット整数の右ローテート
unsigned __int64 _rotr64(_In_ unsigned __int64 _Value, _In_ int _Shift) // 64ビット整数の右ローテート

unsigned long _lrotl(_In_ unsigned long, _In_ int) // 32ビット整数の左ローテート

unsigned long _lrotr(_In_ unsigned long, _In_ int) // 32ビット整数の右ローテート

__int64 __ll_rshift(__int64, int) // 符号付64bit整数の右シフト
unsigned __int64 __ull_rshift(unsigned __int64, int) // 符号なし64bit整数の右シフト
unsigned __int64 __ll_lshift(unsigned __int64, int) // 符号付64bit整数の左シフト

unsigned char _bittest(long const *, long) // 32ビット整数のビット検査
unsigned char _bittestandset(long *, long) // 32ビット整数のビット検査およびセット
unsigned char _bittestandreset(long *, long) // 32ビット整数のビット検査およびリセット
unsigned char _bittestandcomplement(long *, long) // 32ビット整数のビット検査および反転

unsigned short __lzcnt16(unsigned short) // 16ビット整数で、MSBを含む連続したビット0の数を数える
unsigned int __lzcnt(unsigned int) // 32ビット整数で、MSBを含む連続したビット0の数を数える

unsigned short __popcnt16(unsigned short) // 16ビット整数で、1であるビットの数を数える
unsigned int __popcnt(unsigned int) // 32ビット整数で、1であるビットの数を数える

char _InterlockedAnd8(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなAND演算
short _InterlockedAnd16(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなAND演算
long _InterlockedAnd(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなAND演算

char _InterlockedCompareExchange8(char volatile * _Destination, char _Exchange, char _Comparand) // 8ビット整数のアトミックな比較および交換
short _InterlockedCompareExchange16(short volatile * _Destination, short _Exchange, short _Comparand) // 16ビット整数のアトミックな比較および交換
long _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand) // 32ビット整数のアトミックな比較および交換
__int64 _InterlockedCompareExchange64(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand) // 64ビット整数のアトミックな比較および交換

short _InterlockedDecrement16(short volatile * _Addend) // 16ビット整数のアトミックなデクリメント
long _InterlockedDecrement(long volatile * _Addend) // 32ビット整数のアトミックなデクリメント

char _InterlockedExchange8(char volatile * _Target, char _Value) // 8ビット整数のアトミックな交換
short _InterlockedExchange16(short volatile * _Target, short _Value) // 16ビット整数のアトミックな交換
long _InterlockedExchange(long volatile * _Target, long _Value) // 32ビット整数のアトミックな交換

char _InterlockedExchangeAdd8(char volatile * _Addend, char _Value) // 8ビット整数のアトミックな交換および加算
short _InterlockedExchangeAdd16(short volatile * _Addend, short _Value) // 16ビット整数のアトミックな交換および加算
long _InterlockedExchangeAdd(long volatile * _Addend, long _Value) // 32ビット整数のアトミックな交換および加算

short _InterlockedIncrement16(short volatile * _Addend) // 16ビット整数のアトミックなインクリメント
long _InterlockedIncrement(long volatile * _Addend) // 32ビット整数のアトミックなインクリメント

char _InterlockedOr8(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなOR演算
short _InterlockedOr16(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなOR演算
long _InterlockedOr(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなOR演算

char _InterlockedXor8(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなXOR演算
short _InterlockedXor16(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなXOR演算
long _InterlockedXor(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなXOR演算

unsigned char _interlockedbittestandset(long volatile *, long) // 32ビット整数のアトミックなビット検査およびセット
unsigned char _interlockedbittestandreset(long volatile *, long) // 32ビット整数のアトミックなビット検査およびリセット

// 以降、x64のみ

void __movsq(unsigned long long *, unsigned long long const *, size_t) // メモリ移動(64bit)
void __stosq(unsigned __int64 *, unsigned __int64, size_t) // メモリ設定(64bit)

unsigned char _addcarry_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *) // 64ビット符号なし整数のキャリー付加算
unsigned char _subborrow_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *) // 64ビット符号なし整数のボロー付減算

__int64 _mul128(__int64 _Multiplier, __int64 _Multiplicand, __int64 * _HighProduct) // 符号付乗算(64bit * 64bit => 128bit)
unsigned __int64 _umul128(unsigned __int64 _Multiplier, unsigned __int64 _Multiplicand, unsigned __int64 * _HighProduct) // 符号なし乗算(64bit * 64bit => 128bit)

unsigned char _BitScanForward64(unsigned long * _Index, unsigned __int64 _Mask) // LSBからMSBに向かってビット1を検索する
unsigned char _BitScanReverse64(unsigned long * _Index, unsigned __int64 _Mask) // MSBからLSBに向かってビット1を検索する

unsigned __int64 __shiftleft128(unsigned __int64 _LowPart, unsigned __int64 _HighPart, unsigned char _Shift) // 符号なし128bit整数の右シフト
unsigned __int64 __shiftright128(unsigned __int64 _LowPart, unsigned __int64 _HighPart, unsigned char _Shift) // 符号なし128bit整数の左シフト

unsigned __int64 __lzcnt64(unsigned __int64) // 64ビット整数で、MSBを含む連続したビット0の数を数える
unsigned __int64 __popcnt64(unsigned __int64) // 64ビット整数で、1であるビットの数を数える

char _InterlockedAnd8_np(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなAND演算(プリフェッチなし)
short _InterlockedAnd16_np(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなAND演算(プリフェッチなし)
long _InterlockedAnd_np(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなAND演算(プリフェッチなし)
__int64 _InterlockedAnd64_np(__int64 volatile * _Value, __int64 _Mask) // 64ビット整数のアトミックなAND演算(プリフェッチなし)

short _InterlockedCompareExchange16_np(short volatile * _Destination, short _Exchange, short _Comparand) // 16ビット整数のアトミックな比較および交換(プリフェッチなし)
long _InterlockedCompareExchange_np(long volatile * _Destination, long _Exchange, long _Comparand) // 32ビット整数のアトミックな比較および交換(プリフェッチなし)
__int64 _InterlockedCompareExchange64_np(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand) // 64ビット整数のアトミックな比較および交換(プリフェッチなし)
unsigned char _InterlockedCompareExchange128_np(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult) // 128ビット整数のアトミックな比較および交換(プリフェッチなし)

char _InterlockedOr8_np(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなOR演算(プリフェッチなし)
short _InterlockedOr16_np(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなOR演算(プリフェッチなし)
long _InterlockedOr_np(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなOR演算(プリフェッチなし)
__int64 _InterlockedOr64_np(__int64 volatile * _Value, __int64 _Mask) // 64ビット整数のアトミックなOR演算(プリフェッチなし)

char _InterlockedXor8_np(char volatile * _Value, char _Mask) // 8ビット整数のアトミックなXOR演算(プリフェッチなし)
short _InterlockedXor16_np(short volatile * _Value, short _Mask) // 16ビット整数のアトミックなXOR演算(プリフェッチなし)
long _InterlockedXor_np(long volatile * _Value, long _Mask) // 32ビット整数のアトミックなXOR演算(プリフェッチなし)
__int64 _InterlockedXor64_np(__int64 volatile * _Value, __int64 _Mask) // 64ビット整数のアトミックなXOR演算(プリフェッチなし)

*/

#define CPU_FEATURE_FLAG_BMI2   (1U << 8)
#define CPU_FEATURE_FLAG_ADC    (1U << 19)

extern "C"
{
    
#ifdef _IX86
    static const int __ALIGNMENT = alignof(__int32);
#elif defined(_IX64)
    static const int __ALIGNMENT = alignof(__int64);
#else
#endif

    void* _AllocateBuffer(size_t size, size_t* actual_size)
    {
        *actual_size = (size + __ALIGNMENT - 1) / __ALIGNMENT * __ALIGNMENT;
        return (_aligned_malloc(*actual_size, __ALIGNMENT));
    }

    void* _FreeBuffer(size_t size)
    {
        return (_aligned_malloc((size + __ALIGNMENT - 1) / __ALIGNMENT * __ALIGNMENT, __ALIGNMENT));
    }

    // ・x, y, zはNULLではないこと。
    // ・x, y, zは unsigned __int32の アライメント条件を満たしていること。
    // ・x_lengthおよびy_lengthは sizeof(unsigned long) の倍数であること。
    // ・x_length >= y_length であること。
    // ・z_lengthはNULLではないこと。
    void __stdcall _UM_Add_ADC32(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        unsigned __int32* x_ptr = (unsigned __int32*)x;
        unsigned __int32* y_ptr = (unsigned __int32*)y;
        unsigned __int32* z_ptr = (unsigned __int32*)z;
        size_t count1 = y_length / sizeof(unsigned __int32);
        size_t count2 = x_length / sizeof(unsigned __int32) - count1;
        char carry = 0;
        while (count1 >= 8)
        {
            carry = _addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3), *(x_ptr + 4), *(y_ptr + 4), z_ptr + 4), *(x_ptr + 5), *(y_ptr + 5), z_ptr + 5), *(x_ptr + 6), *(y_ptr + 6), z_ptr + 6), *(x_ptr + 7), *(y_ptr + 7), z_ptr + 7);
            x_ptr += 8;
            y_ptr += 8;
            z_ptr += 8;
            count1 -= 8;
        }
        if (count1 >= 4)
        {
            carry = _addcarry_u32(_addcarry_u32(_addcarry_u32(_addcarry_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3);
            x_ptr += 4;
            y_ptr += 4;
            z_ptr += 4;
            count1 -= 4;
        }
        if (count1 >= 2)
        {
            carry = _addcarry_u32(_addcarry_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1);
            x_ptr += 2;
            y_ptr += 2;
            z_ptr += 2;
            count1 -= 2;
        }
        if (count1)
        {
            carry = _addcarry_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0);
            x_ptr += 1;
            y_ptr += 1;
            z_ptr += 1;
            count1 -= 1;
        }
        while (carry && count2)
        {
            carry = _addcarry_u32(carry, *x_ptr, 0, z_ptr);
            ++x_ptr;
            ++z_ptr;
            --count2;
        }
        if (carry)
        {
            *z_ptr = 1;
            ++z_ptr;
        }
        else if (count2)
        {
            __movsd((unsigned long*)z_ptr, (const unsigned long*)x_ptr, count2);
            z_ptr += count2;
        }
        else
        {
        }
        while (z_ptr > z && *(z_ptr - 1) == 0)
            --z_ptr;
        *z_length = (z_ptr - (unsigned __int32 *)z) * sizeof(unsigned __int32);
    }

    // ・x, y, zはNULLではないこと。
    // ・x, y, zは unsigned __int32の アライメント条件を満たしていること。
    // ・x_lengthおよびy_lengthは sizeof(unsigned __int32) の倍数であること。
    // ・x_length >= y_length であること。
    // ・z_lengthはNULLではないこと。
    void __stdcall _UM_Add_ADCX32(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        unsigned __int32* x_ptr = (unsigned __int32*)x;
        unsigned __int32* y_ptr = (unsigned __int32*)y;
        unsigned __int32* z_ptr = (unsigned __int32*)z;
        size_t count1 = y_length / sizeof(unsigned __int32);
        size_t count2 = x_length / sizeof(unsigned __int32) - count1;
        char carry = 0;
        while (count1 >= 8)
        {
            carry = _addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3), *(x_ptr + 4), *(y_ptr + 4), z_ptr + 4), *(x_ptr + 5), *(y_ptr + 5), z_ptr + 5), *(x_ptr + 6), *(y_ptr + 6), z_ptr + 6), *(x_ptr + 7), *(y_ptr + 7), z_ptr + 7);
            x_ptr += 8;
            y_ptr += 8;
            z_ptr += 8;
            count1 -= 8;
        }
        if (count1 >= 4)
        {
            carry = _addcarryx_u32(_addcarryx_u32(_addcarryx_u32(_addcarryx_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3);
            x_ptr += 4;
            y_ptr += 4;
            z_ptr += 4;
            count1 -= 4;
        }
        if (count1 >= 2)
        {
            carry = _addcarryx_u32(_addcarryx_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1);
            x_ptr += 2;
            y_ptr += 2;
            z_ptr += 2;
            count1 -= 2;
        }
        if (count1)
        {
            carry = _addcarryx_u32(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0);
            x_ptr += 1;
            y_ptr += 1;
            z_ptr += 1;
            count1 -= 1;
        }
        while (carry && count2)
        {
            carry = _addcarryx_u32(carry, *x_ptr, 0, z_ptr);
            ++x_ptr;
            ++z_ptr;
            --count2;
        }
        if (carry)
        {
            *z_ptr = 1;
            ++z_ptr;
        }
        else if (count2)
        {
            __movsd((unsigned long*)z_ptr, (const unsigned long*)x_ptr, count2);
            z_ptr += count2;
        }
        else
        {
        }
        while (z_ptr > z && *(z_ptr - 1) == 0)
            --z_ptr;
        *z_length = (z_ptr - (unsigned __int32 *)z) * sizeof(unsigned __int32);
    }

#ifdef _IX64
    // ・x, y, zはNULLではないこと。
    // ・x, y, zは unsigned __int64の アライメント条件を満たしていること。
    // ・x_lengthおよびy_lengthは sizeof(unsigned __int64) の倍数であること。
    // ・x_length >= y_length であること。
    // ・z_lengthはNULLではないこと。
    void __stdcall _UM_Add_ADC64(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        unsigned __int64* x_ptr = (unsigned __int64*)x;
        unsigned __int64* y_ptr = (unsigned __int64*)y;
        unsigned __int64* z_ptr = (unsigned __int64*)z;
        size_t count1 = y_length / sizeof(unsigned __int64);
        size_t count2 = x_length / sizeof(unsigned __int64) - count1;
        char carry = 0;
        while (count1 >= 8)
        {
            carry = _addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3), *(x_ptr + 4), *(y_ptr + 4), z_ptr + 4), *(x_ptr + 5), *(y_ptr + 5), z_ptr + 5), *(x_ptr + 6), *(y_ptr + 6), z_ptr + 6), *(x_ptr + 7), *(y_ptr + 7), z_ptr + 7);
            x_ptr += 8;
            y_ptr += 8;
            z_ptr += 8;
            count1 -= 8;
        }
        if (count1 >= 4)
        {
            carry = _addcarry_u64(_addcarry_u64(_addcarry_u64(_addcarry_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3);
            x_ptr += 4;
            y_ptr += 4;
            z_ptr += 4;
            count1 -= 4;
        }
        if (count1 >= 2)
        {
            carry = _addcarry_u64(_addcarry_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1);
            x_ptr += 2;
            y_ptr += 2;
            z_ptr += 2;
            count1 -= 2;
        }
        if (count1)
        {
            carry = _addcarry_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0);
            x_ptr += 1;
            y_ptr += 1;
            z_ptr += 1;
            count1 -= 1;
        }
        while (carry && count2)
        {
            carry = _addcarry_u64(carry, *x_ptr, 0, z_ptr);
            ++x_ptr;
            ++z_ptr;
            --count2;
        }
        if (carry)
        {
            *z_ptr = 1;
            ++z_ptr;
        }
        else if (count2)
        {
            __movsq((PDWORD64)z_ptr, (const DWORD64*)x_ptr, count2);
            z_ptr += count2;
        }
        else
        {
        }
        while (z_ptr > z && *(z_ptr - 1) == 0)
            --z_ptr;
        *z_length = (z_ptr - (unsigned __int64 *)z) * sizeof(unsigned __int64);
    }

    // ・x, y, zはNULLではないこと。
    // ・x, y, zは unsigned __int64の アライメント条件を満たしていること。
    // ・x_lengthおよびy_lengthは sizeof(unsigned __int64) の倍数であること。
    // ・x_length >= y_length であること。
    // ・z_lengthはNULLではないこと。
    void __stdcall _UM_Add_ADCX64(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        unsigned __int64* x_ptr = (unsigned __int64*)x;
        unsigned __int64* y_ptr = (unsigned __int64*)y;
        unsigned __int64* z_ptr = (unsigned __int64*)z;
        size_t count1 = y_length / sizeof(unsigned __int64);
        size_t count2 = x_length / sizeof(unsigned __int64) - count1;
        char carry = 0;
        while (count1 >= 8)
        {
            carry = _addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3), *(x_ptr + 4), *(y_ptr + 4), z_ptr + 4), *(x_ptr + 5), *(y_ptr + 5), z_ptr + 5), *(x_ptr + 6), *(y_ptr + 6), z_ptr + 6), *(x_ptr + 7), *(y_ptr + 7), z_ptr + 7);
            x_ptr += 8;
            y_ptr += 8;
            z_ptr += 8;
            count1 -= 8;
        }
        if (count1 >= 4)
        {
            carry = _addcarryx_u64(_addcarryx_u64(_addcarryx_u64(_addcarryx_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1), *(x_ptr + 2), *(y_ptr + 2), z_ptr + 2), *(x_ptr + 3), *(y_ptr + 3), z_ptr + 3);
            x_ptr += 4;
            y_ptr += 4;
            z_ptr += 4;
            count1 -= 4;
        }
        if (count1 >= 2)
        {
            carry = _addcarryx_u64(_addcarryx_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0), *(x_ptr + 1), *(y_ptr + 1), z_ptr + 1);
            x_ptr += 2;
            y_ptr += 2;
            z_ptr += 2;
            count1 -= 2;
        }
        if (count1)
        {
            carry = _addcarryx_u64(carry, *(x_ptr + 0), *(y_ptr + 0), z_ptr + 0);
            x_ptr += 1;
            y_ptr += 1;
            z_ptr += 1;
            count1 -= 1;
        }
        while (carry && count2)
        {
            carry = _addcarryx_u64(carry, *x_ptr, 0, z_ptr);
            ++x_ptr;
            ++z_ptr;
            --count2;
        }
        if (carry)
        {
            *z_ptr = 1;
            ++z_ptr;
        }
        else if (count2)
        {
            __movsq((PDWORD64)z_ptr, (const DWORD64*)x_ptr, count2);
            z_ptr += count2;
        }
        else
        {
        }
        while (z_ptr > z && *(z_ptr - 1) == 0)
            --z_ptr;
        *z_length = (z_ptr - (unsigned __int64 *)z) * sizeof(unsigned __int64);
    }
#endif

    static void (__stdcall *_UM_EntryPoint_Add)(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length) = _UM_Add_ADC32;

    __declspec(dllexport) int __stdcall UM_Initialize()
    {
#if defined(_IX86) || defined(_IX64)
        int cpu_id_buffer[4];
        __cpuid(cpu_id_buffer, 0);
        if (cpu_id_buffer[0] < 7)
        {
#ifdef _IX64
            _UM_EntryPoint_Add = _UM_Add_ADC64;
#else // _IX64
            _UM_EntryPoint_Add = _UM_Add_ADC32;
#endif // _IX64
        }
        else
        {
            __cpuid(cpu_id_buffer, 7);
            if (cpu_id_buffer[1] & CPU_FEATURE_FLAG_ADC)
            {
#ifdef _IX64
                _UM_EntryPoint_Add = _UM_Add_ADCX64;
#else // _IX64
                _UM_EntryPoint_Add = _UM_Add_ADCX32;
#endif // _IX64
            }
            else
            {
#ifdef _IX64
                _UM_EntryPoint_Add = _UM_Add_ADC64;
#else // _IX64
                _UM_EntryPoint_Add = _UM_Add_ADC32;
#endif // _IX64
            }
        }
        return (TRUE);
    }
#else
        return (FALSE);
#endif

    __declspec(dllexport) void* __stdcall UM_AllocateBuffer(size_t size, size_t* actual_size)
    {
        return (_AllocateBuffer(size, actual_size));
    }

    __declspec(dllexport) void* __stdcall UM_FromUint32(unsigned __int32 value, size_t* buffer_size)
    {
        unsigned __int32* buffer = (unsigned __int32*)_AllocateBuffer(sizeof(unsigned __int32), buffer_size);
        *buffer = value;
        if (value == 0)
            *buffer_size = 0;
        return (buffer);
    }

    __declspec(dllexport) void* __stdcall UM_FromUint64(unsigned __int64 value, size_t* buffer_size)
    {
#ifdef _IX64
        unsigned __int64* buffer = (unsigned __int64*)_AllocateBuffer(sizeof(unsigned __int32), buffer_size);
        *buffer = value;
        if (value == 0)
            *buffer_size = 0;
        return (buffer);
#else // _IX64
        unsigned __int32* buffer = (unsigned __int32*)_AllocateBuffer(sizeof(unsigned __int32) * 2, buffer_size);
        buffer[0] = (unsigned __int32)value;
        buffer[1] = (unsigned __int32)(value>> 32);
        if (value == 0)
            *buffer_size = 0;
        return (buffer);
#endif // _IX64
    }

    __declspec(dllexport) void __stdcall UM_FreeBuffer(void* p)
    {
        _aligned_free(p);
    }

    __declspec(dllexport) void __stdcall UM_Add(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        if (x_length >= y_length)
            (*_UM_EntryPoint_Add)(x, x_length, y, y_length, z, z_length);
        else
            (*_UM_EntryPoint_Add)(y, y_length, x, x_length, z, z_length);
    }
}