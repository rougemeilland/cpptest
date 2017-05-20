// Test.CppTest.CppProject.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

// CPUID�ɂ���:
//   http://www.wdic.org/w/SCI/cpuid%20%28x86%29
// �g�ݍ��݊֐��ɂ���:
//   https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=Other // �{��(�p��)
//   https://msdn.microsoft.com/ja-jp/library/hh977023.aspx // MS

#include <windows.h>
#include <malloc.h>
#include <intrin.h>
#include <immintrin.h>
#include "Source.h"

/*
unsigned __int64 _byteswap_uint64(_In_ unsigned __int64) // �o�C�g�I�[�_�[�ϊ�(64bit)
unsigned long _byteswap_ulong(_In_ unsigned long) // �o�C�g�I�[�_�[�ϊ�(32bit)
unsigned short _byteswap_ushort(_In_ unsigned short) // �o�C�g�I�[�_�[�ϊ�(16bit)

void __movsb(unsigned char *, unsigned char const *, size_t) // �������ړ�(8bit)
void __movsw(unsigned short *, unsigned short const *, size_t) // �������ړ�(16bit)
void __movsd(unsigned long *, unsigned long const *, size_t) // �������ړ�(32bit)

void __stosb(unsigned char *, unsigned char, size_t) // �������ݒ�(8bit)
void __stosw(unsigned short *, unsigned short, size_t) // �������ݒ�(16bit)
void __stosd(unsigned long *, unsigned long, size_t) // �������ݒ�(32bit)

unsigned char _addcarry_u8(unsigned char, unsigned char, unsigned char, unsigned char *) // 8�r�b�g�����Ȃ������̃L�����[�t���Z
unsigned char _addcarry_u16(unsigned char, unsigned short, unsigned short, unsigned short *) // 16�r�b�g�����Ȃ������̃L�����[�t���Z
unsigned char _addcarry_u32(unsigned char, unsigned int, unsigned int, unsigned int *) // 32�r�b�g�����Ȃ������̃L�����[�t���Z

unsigned char _subborrow_u8(unsigned char, unsigned char, unsigned char, unsigned char *) // 8�r�b�g�����Ȃ������̃{���[�t���Z
unsigned char _subborrow_u16(unsigned char, unsigned short, unsigned short, unsigned short *) // 8�r�b�g�����Ȃ������̃{���[�t���Z
unsigned char _subborrow_u32(unsigned char, unsigned int, unsigned int, unsigned int *) // 8�r�b�g�����Ȃ������̃{���[�t���Z

__int64 __emul(int, int) // �����t��Z(32bit * 32bit => 64bit)
unsigned __int64 __emulu(unsigned int, unsigned int) // �����Ȃ���Z(32bit * 32bit => 64bit)

unsigned char _BitScanForward(unsigned long * _Index, unsigned long _Mask) // LSB����MSB�Ɍ������ăr�b�g1����������
unsigned char _BitScanReverse(unsigned long * _Index, unsigned long _Mask) // MSB����LSB�Ɍ������ăr�b�g1����������

unsigned char _rotl8(unsigned char _Value, unsigned char _Shift) // 8�r�b�g�����̍����[�e�[�g
unsigned short _rotl16(unsigned short _Value, unsigned char _Shift) // 16�r�b�g�����̍����[�e�[�g
unsigned int _rotl(_In_ unsigned int _Value, _In_ int _Shift) // 32�r�b�g�����̍����[�e�[�g
unsigned __int64 _rotl64(_In_ unsigned __int64 _Value, _In_ int _Shift) // 64�r�b�g�����̍����[�e�[�g

unsigned char _rotr8(unsigned char _Value, unsigned char _Shift) // 8�r�b�g�����̍����[�e�[�g
unsigned short _rotr16(unsigned short _Value, unsigned char _Shift) // 16�r�b�g�����̍����[�e�[�g
unsigned int _rotr(_In_ unsigned int _Value, _In_ int _Shift) // �r�b�g�����̉E���[�e�[�g
unsigned __int64 _rotr64(_In_ unsigned __int64 _Value, _In_ int _Shift) // 64�r�b�g�����̉E���[�e�[�g

unsigned long _lrotl(_In_ unsigned long, _In_ int) // 32�r�b�g�����̍����[�e�[�g

unsigned long _lrotr(_In_ unsigned long, _In_ int) // 32�r�b�g�����̉E���[�e�[�g

__int64 __ll_rshift(__int64, int) // �����t64bit�����̉E�V�t�g
unsigned __int64 __ull_rshift(unsigned __int64, int) // �����Ȃ�64bit�����̉E�V�t�g
unsigned __int64 __ll_lshift(unsigned __int64, int) // �����t64bit�����̍��V�t�g

unsigned char _bittest(long const *, long) // 32�r�b�g�����̃r�b�g����
unsigned char _bittestandset(long *, long) // 32�r�b�g�����̃r�b�g��������уZ�b�g
unsigned char _bittestandreset(long *, long) // 32�r�b�g�����̃r�b�g��������у��Z�b�g
unsigned char _bittestandcomplement(long *, long) // 32�r�b�g�����̃r�b�g��������є��]

unsigned short __lzcnt16(unsigned short) // 16�r�b�g�����ŁAMSB���܂ޘA�������r�b�g0�̐��𐔂���
unsigned int __lzcnt(unsigned int) // 32�r�b�g�����ŁAMSB���܂ޘA�������r�b�g0�̐��𐔂���

unsigned short __popcnt16(unsigned short) // 16�r�b�g�����ŁA1�ł���r�b�g�̐��𐔂���
unsigned int __popcnt(unsigned int) // 32�r�b�g�����ŁA1�ł���r�b�g�̐��𐔂���

char _InterlockedAnd8(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��AND���Z
short _InterlockedAnd16(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��AND���Z
long _InterlockedAnd(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��AND���Z

char _InterlockedCompareExchange8(char volatile * _Destination, char _Exchange, char _Comparand) // 8�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���
short _InterlockedCompareExchange16(short volatile * _Destination, short _Exchange, short _Comparand) // 16�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���
long _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand) // 32�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���
__int64 _InterlockedCompareExchange64(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand) // 64�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���

short _InterlockedDecrement16(short volatile * _Addend) // 16�r�b�g�����̃A�g�~�b�N�ȃf�N�������g
long _InterlockedDecrement(long volatile * _Addend) // 32�r�b�g�����̃A�g�~�b�N�ȃf�N�������g

char _InterlockedExchange8(char volatile * _Target, char _Value) // 8�r�b�g�����̃A�g�~�b�N�Ȍ���
short _InterlockedExchange16(short volatile * _Target, short _Value) // 16�r�b�g�����̃A�g�~�b�N�Ȍ���
long _InterlockedExchange(long volatile * _Target, long _Value) // 32�r�b�g�����̃A�g�~�b�N�Ȍ���

char _InterlockedExchangeAdd8(char volatile * _Addend, char _Value) // 8�r�b�g�����̃A�g�~�b�N�Ȍ�������щ��Z
short _InterlockedExchangeAdd16(short volatile * _Addend, short _Value) // 16�r�b�g�����̃A�g�~�b�N�Ȍ�������щ��Z
long _InterlockedExchangeAdd(long volatile * _Addend, long _Value) // 32�r�b�g�����̃A�g�~�b�N�Ȍ�������щ��Z

short _InterlockedIncrement16(short volatile * _Addend) // 16�r�b�g�����̃A�g�~�b�N�ȃC���N�������g
long _InterlockedIncrement(long volatile * _Addend) // 32�r�b�g�����̃A�g�~�b�N�ȃC���N�������g

char _InterlockedOr8(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��OR���Z
short _InterlockedOr16(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��OR���Z
long _InterlockedOr(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��OR���Z

char _InterlockedXor8(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��XOR���Z
short _InterlockedXor16(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��XOR���Z
long _InterlockedXor(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��XOR���Z

unsigned char _interlockedbittestandset(long volatile *, long) // 32�r�b�g�����̃A�g�~�b�N�ȃr�b�g��������уZ�b�g
unsigned char _interlockedbittestandreset(long volatile *, long) // 32�r�b�g�����̃A�g�~�b�N�ȃr�b�g��������у��Z�b�g

// �ȍ~�Ax64�̂�

void __movsq(unsigned long long *, unsigned long long const *, size_t) // �������ړ�(64bit)
void __stosq(unsigned __int64 *, unsigned __int64, size_t) // �������ݒ�(64bit)

unsigned char _addcarry_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *) // 64�r�b�g�����Ȃ������̃L�����[�t���Z
unsigned char _subborrow_u64(unsigned char, unsigned __int64, unsigned __int64, unsigned __int64 *) // 64�r�b�g�����Ȃ������̃{���[�t���Z

__int64 _mul128(__int64 _Multiplier, __int64 _Multiplicand, __int64 * _HighProduct) // �����t��Z(64bit * 64bit => 128bit)
unsigned __int64 _umul128(unsigned __int64 _Multiplier, unsigned __int64 _Multiplicand, unsigned __int64 * _HighProduct) // �����Ȃ���Z(64bit * 64bit => 128bit)

unsigned char _BitScanForward64(unsigned long * _Index, unsigned __int64 _Mask) // LSB����MSB�Ɍ������ăr�b�g1����������
unsigned char _BitScanReverse64(unsigned long * _Index, unsigned __int64 _Mask) // MSB����LSB�Ɍ������ăr�b�g1����������

unsigned __int64 __shiftleft128(unsigned __int64 _LowPart, unsigned __int64 _HighPart, unsigned char _Shift) // �����Ȃ�128bit�����̉E�V�t�g
unsigned __int64 __shiftright128(unsigned __int64 _LowPart, unsigned __int64 _HighPart, unsigned char _Shift) // �����Ȃ�128bit�����̍��V�t�g

unsigned __int64 __lzcnt64(unsigned __int64) // 64�r�b�g�����ŁAMSB���܂ޘA�������r�b�g0�̐��𐔂���
unsigned __int64 __popcnt64(unsigned __int64) // 64�r�b�g�����ŁA1�ł���r�b�g�̐��𐔂���

char _InterlockedAnd8_np(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��AND���Z(�v���t�F�b�`�Ȃ�)
short _InterlockedAnd16_np(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��AND���Z(�v���t�F�b�`�Ȃ�)
long _InterlockedAnd_np(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��AND���Z(�v���t�F�b�`�Ȃ�)
__int64 _InterlockedAnd64_np(__int64 volatile * _Value, __int64 _Mask) // 64�r�b�g�����̃A�g�~�b�N��AND���Z(�v���t�F�b�`�Ȃ�)

short _InterlockedCompareExchange16_np(short volatile * _Destination, short _Exchange, short _Comparand) // 16�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���(�v���t�F�b�`�Ȃ�)
long _InterlockedCompareExchange_np(long volatile * _Destination, long _Exchange, long _Comparand) // 32�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���(�v���t�F�b�`�Ȃ�)
__int64 _InterlockedCompareExchange64_np(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand) // 64�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���(�v���t�F�b�`�Ȃ�)
unsigned char _InterlockedCompareExchange128_np(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult) // 128�r�b�g�����̃A�g�~�b�N�Ȕ�r����ь���(�v���t�F�b�`�Ȃ�)

char _InterlockedOr8_np(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��OR���Z(�v���t�F�b�`�Ȃ�)
short _InterlockedOr16_np(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��OR���Z(�v���t�F�b�`�Ȃ�)
long _InterlockedOr_np(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��OR���Z(�v���t�F�b�`�Ȃ�)
__int64 _InterlockedOr64_np(__int64 volatile * _Value, __int64 _Mask) // 64�r�b�g�����̃A�g�~�b�N��OR���Z(�v���t�F�b�`�Ȃ�)

char _InterlockedXor8_np(char volatile * _Value, char _Mask) // 8�r�b�g�����̃A�g�~�b�N��XOR���Z(�v���t�F�b�`�Ȃ�)
short _InterlockedXor16_np(short volatile * _Value, short _Mask) // 16�r�b�g�����̃A�g�~�b�N��XOR���Z(�v���t�F�b�`�Ȃ�)
long _InterlockedXor_np(long volatile * _Value, long _Mask) // 32�r�b�g�����̃A�g�~�b�N��XOR���Z(�v���t�F�b�`�Ȃ�)
__int64 _InterlockedXor64_np(__int64 volatile * _Value, __int64 _Mask) // 64�r�b�g�����̃A�g�~�b�N��XOR���Z(�v���t�F�b�`�Ȃ�)

*/

#define CPU_FEATURE_FLAG_BMI2   (1U << 8)
#define CPU_FEATURE_FLAG_ADC    (1U << 19)

extern "C"
{

#ifdef _IX86
    typedef unsigned __int32 __UNIT_TYPE;
#elif defined(_IX64)
    typedef unsigned __int64 __UNIT_TYPE;
#else
    // undefined
#endif

    __UNIT_TYPE* _AllocateBuffer(size_t size)
    {
        if (size == 0)
            return ((__UNIT_TYPE*)_aligned_malloc(sizeof(__UNIT_TYPE), alignof(__UNIT_TYPE)));
        else
            return ((__UNIT_TYPE*)_aligned_malloc((size + sizeof(__UNIT_TYPE) - 1) / sizeof(__UNIT_TYPE) * sizeof(__UNIT_TYPE), alignof(__UNIT_TYPE)));
    }

    __UNIT_TYPE* _AllocateZeroClearedBuffer(size_t size)
    {
        if (size == 0)
            return ((__UNIT_TYPE*)_aligned_malloc(sizeof(__UNIT_TYPE), alignof(__UNIT_TYPE)));
        else
        {
            size_t unit_count = (size + sizeof(__UNIT_TYPE) - 1) / sizeof(__UNIT_TYPE);
            size_t actual_size = unit_count * sizeof(__UNIT_TYPE);
            __UNIT_TYPE* buffer = (__UNIT_TYPE*)_aligned_malloc(actual_size, alignof(__UNIT_TYPE));
#ifdef _IX64
            __stosq(buffer, 0, unit_count);
#else // _IX64
            __stosd((unsigned long *)buffer, 0, unit_count);
#endif // _IX64
            return (buffer);
        }
    }

    void _FreeBuffer(__UNIT_TYPE* buffer)
    {
        _aligned_free(buffer);
    }

    int _UM_SetUint32Value_Imp(void * buffer, size_t * buffer_size, unsigned int value)
    {
        if (buffer == NULL)
            return (FALSE);
        if (buffer_size == NULL)
            return (FALSE);
        size_t actual_size = sizeof(__UNIT_TYPE) > sizeof(unsigned __int32) ? sizeof(__UNIT_TYPE) : sizeof(unsigned __int32);
        if (*buffer_size < actual_size)
            return (FALSE);
        size_t word_count = actual_size / sizeof(unsigned __int32);
        *buffer_size = actual_size;
        unsigned __int32* p = (unsigned __int32*)buffer;
        p[0] = value;
        switch (word_count)
        {
        case 4:
            p[3] = 0;
        case 3:
            p[2] = 0;
        case 2:
            p[1] = 0;
        case 1:
            break;
        default:
            __stosd((PDWORD)&p[1], 0, word_count - 1);
            break;
        }
        return (TRUE);
    }

    int _UM_SetUint64Value_Imp_x86(void * buffer, size_t * buffer_size, unsigned int value_high, unsigned int value_low)
    {
        if (buffer == NULL)
            return (FALSE);
        if (buffer_size == NULL)
            return (FALSE);
        size_t actual_size = sizeof(__UNIT_TYPE) > sizeof(unsigned __int32) * 2 ? sizeof(__UNIT_TYPE) : sizeof(unsigned __int32) * 2;
        if (*buffer_size < actual_size)
            return (FALSE);
        size_t word_count = actual_size / sizeof(unsigned __int32);
        *buffer_size = actual_size;
        unsigned __int32* p = (unsigned __int32*)buffer;
        p[0] = value_low;
        p[1] = value_high;
        switch (word_count)
        {
        case 4:
            p[3] = 0;
        case 3:
            p[2] = 0;
        case 2:
        case 1:
            break;
        default:
            __stosd((PDWORD)&p[2], 0, word_count - 2);
            break;
        }
        return (TRUE);
    }

#ifdef _IX64
    int _UM_SetUint64Value_Imp_x64(void * buffer, size_t * buffer_size, unsigned long long value)
    {
        if (buffer == NULL)
            return (FALSE);
        if (buffer_size == NULL)
            return (FALSE);
        size_t actual_size = sizeof(__UNIT_TYPE) > sizeof(unsigned __int64) ? sizeof(__UNIT_TYPE) : sizeof(unsigned __int64);
        if (*buffer_size < actual_size)
            return (FALSE);
        size_t word_count = actual_size / sizeof(unsigned __int64);
        *buffer_size = actual_size;
        unsigned __int64* p = (unsigned __int64*)buffer;
        p[0] = value;
        switch (word_count)
        {
        case 4:
            p[3] = 0;
        case 3:
            p[2] = 0;
        case 2:
            p[1] = 0;
        case 1:
            break;
        default:
            __stosq((PDWORD64)&p[1], 0, word_count - 1);
            break;
        }
        return (TRUE);
    }
#endif // _IX64

    // �Ex, y, z��NULL�ł͂Ȃ����ƁB
    // �Ex, y, z�� unsigned __int32�� �A���C�����g�����𖞂����Ă��邱�ƁB
    // �Ex_length�����y_length�� sizeof(unsigned long) �̔{���ł��邱�ƁB
    // �Ex_length >= y_length �ł��邱�ƁB
    // �Ez_length��NULL�ł͂Ȃ����ƁB
    int __stdcall _UM_Add_ADC32(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
#if _DEBUG
        if (x == NULL)
            return (FALSE);
        if (y == NULL)
            return (FALSE);
        if (z == NULL)
            return (FALSE);
        if (z_length == NULL)
            return (FALSE);
        if (x_length < y_length)
            return (FALSE);
        if (*z_length < x_length)
            return (FALSE);
        unsigned __int32* z_ptr_limit = (unsigned __int32*)((unsigned char*)z + *z_length);
#endif // _DEBUG
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
#if _DEBUG
            if (z_ptr >= z_ptr_limit)
                return (FALSE);
#endif // _DEBUG
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
        *z_length = (unsigned char*)z_ptr - (unsigned char*)z;
        return (TRUE);
    }

    // �Ex, y, z��NULL�ł͂Ȃ����ƁB
    // �Ex, y, z�� unsigned __int32�� �A���C�����g�����𖞂����Ă��邱�ƁB
    // �Ex_length�����y_length�� sizeof(unsigned __int32) �̔{���ł��邱�ƁB
    // �Ex_length >= y_length �ł��邱�ƁB
    // �Ez_length��NULL�ł͂Ȃ����ƁB
    int __stdcall _UM_Add_ADCX32(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
#if _DEBUG
        if (x == NULL)
            return (FALSE);
        if (y == NULL)
            return (FALSE);
        if (z == NULL)
            return (FALSE);
        if (z_length == NULL)
            return (FALSE);
        if (x_length < y_length)
            return (FALSE);
        if (*z_length < x_length)
            return (FALSE);
        unsigned __int32* z_ptr_limit = (unsigned __int32*)((unsigned char*)z + *z_length);
#endif // _DEBUG
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
#if _DEBUG
            if (z_ptr >= z_ptr_limit)
                return (FALSE);
#endif // _DEBUG
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
        *z_length = (unsigned char*)z_ptr - (unsigned char*)z;
        return (TRUE);
    }

#ifdef _IX64
    // �Ex, y, z��NULL�ł͂Ȃ����ƁB
    // �Ex, y, z�� unsigned __int64�� �A���C�����g�����𖞂����Ă��邱�ƁB
    // �Ex_length�����y_length�� sizeof(unsigned __int64) �̔{���ł��邱�ƁB
    // �Ex_length >= y_length �ł��邱�ƁB
    // �Ez_length��NULL�ł͂Ȃ����ƁB
    int __stdcall _UM_Add_ADC64(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
#if _DEBUG
        if (x == NULL)
            return (FALSE);
        if (y == NULL)
            return (FALSE);
        if (z == NULL)
            return (FALSE);
        if (z_length == NULL)
            return (FALSE);
        if (x_length < y_length)
            return (FALSE);
        if (*z_length < x_length)
            return (FALSE);
        unsigned __int64* z_ptr_limit = (unsigned __int64*)((unsigned char*)z + *z_length);
#endif // _DEBUG
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
#if _DEBUG
            if (z_ptr >= z_ptr_limit)
                return (FALSE);
#endif // _DEBUG
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
        *z_length = (unsigned char*)z_ptr - (unsigned char*)z;
        return (TRUE);
    }

    // �Ex, y, z��NULL�ł͂Ȃ����ƁB
    // �Ex, y, z�� unsigned __int64�� �A���C�����g�����𖞂����Ă��邱�ƁB
    // �Ex_length�����y_length�� sizeof(unsigned __int64) �̔{���ł��邱�ƁB
    // �Ex_length >= y_length �ł��邱�ƁB
    // �Ez_length��NULL�ł͂Ȃ����ƁB
    int __stdcall _UM_Add_ADCX64(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
#if _DEBUG
        if (x == NULL)
            return (FALSE);
        if (y == NULL)
            return (FALSE);
        if (z == NULL)
            return (FALSE);
        if (z_length == NULL)
            return (FALSE);
        if (x_length < y_length)
            return (FALSE);
        if (*z_length < x_length)
            return (FALSE);
        unsigned __int64* z_ptr_limit = (unsigned __int64*)((unsigned char*)z + *z_length);
#endif // _DEBUG
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
#if _DEBUG
            if (z_ptr >= z_ptr_limit)
                return (FALSE);
#endif // _DEBUG
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
        *z_length = (unsigned char*)z_ptr - (unsigned char*)z;
        return (TRUE);
    }
#endif

    size_t _NormalizeBufferSize(const void* buffer, size_t size)
    {
#ifdef _IX64
        unsigned __int64* p1 = (unsigned __int64*)buffer;
        unsigned __int64* p2 = (unsigned __int64*)((unsigned char*)buffer + size);
#else // _IX64
        unsigned __int32* p1 = (unsigned __int32*)buffer;
        unsigned __int32* p2 = (unsigned __int32*)((unsigned char*)buffer + size);
#endif // _IX64
        while (p2 > p1 && *(p2 - 1) == 0)
            --p2;
        return ((unsigned char*)p2 - (unsigned char*)p1);
    }

    static int(__stdcall *_UM_EntryPoint_Add)(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length) = _UM_Add_ADC32;

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
#else
        return (FALSE);
#endif
    }

    __declspec(dllexport) void* __stdcall UM_AllocateBuffer(size_t size)
    {
        return (_AllocateBuffer(size));
    }

    __declspec(dllexport) int __stdcall UM_SetUint32Value(void* buffer, size_t* buffer_size, unsigned __int32 value)
    {
        if (value == 0)
        {
            *buffer_size = 0;
            return (TRUE);
        }
        return (_UM_SetUint32Value_Imp(buffer, buffer_size, value));
    }

    __declspec(dllexport) int __stdcall UM_SetUint64Value(void* buffer, size_t* buffer_size, unsigned __int64 value)
    {
        if (value == 0)
        {
            *buffer_size = 0;
            return (TRUE);
        }
        else
        {
#ifdef _IX64
            return (_UM_SetUint64Value_Imp_x64(buffer, buffer_size, value));
#else // _IX64
            unsigned __int32 value_low = (unsigned __int32)value;
            unsigned __int32 value_high = (unsigned __int32)(value >> 32);
            if (value_high == 0)
                return (_UM_SetUint32Value_Imp(buffer, buffer_size, value_low));
            else
                return (_UM_SetUint64Value_Imp_x86(buffer, buffer_size, value_high, value_low));
#endif // _IX64
        }
    }

    __declspec(dllexport) void __stdcall UM_FreeBuffer(void* p)
    {
        _aligned_free(p);
    }

    __declspec(dllexport) int __stdcall UM_Add(void* x, size_t x_length, void*  y, size_t y_length, void* z, size_t* z_length)
    {
        if (x_length == 0)
        {
            if (y_length == 0)
            {
                *z_length = 0;
                return (TRUE);
            }
            else
            {
                if (*z_length < y_length)
                    return (FALSE);
#ifdef _IX64
                __movsq((DWORD64*)z, (DWORD64*)y, y_length / sizeof(unsigned __int64));
#else // _IX64
                __movsd((unsigned long*)z, (unsigned long*)y, y_length / sizeof(unsigned long));
#endif // _IX64
                *z_length = _NormalizeBufferSize(z, y_length);
                return (TRUE);
            }
        }
        else
        {
            if (y_length == 0)
            {
                if (*z_length < x_length)
                    return (FALSE);
#ifdef _IX64
                __movsq((DWORD64*)z, (DWORD64*)x, x_length / sizeof(unsigned __int64));
#else // _IX64
                __movsd((unsigned long*)z, (unsigned long*)x, x_length / sizeof(unsigned long));
#endif // _IX64
                *z_length = _NormalizeBufferSize(z, x_length);
                return (TRUE);
            }
            else
            {
                if (x_length >= y_length)
                {
                    if (!(*_UM_EntryPoint_Add)(x, x_length, y, y_length, z, z_length))
                        return (FALSE);
                }
                else
                {
                    if (!(*_UM_EntryPoint_Add)(y, y_length, x, x_length, z, z_length))
                        return (FALSE);
                }
                *z_length = _NormalizeBufferSize(z, *z_length);
                return (TRUE);
            }
        }
            }
    }