// Test.CppTest.CppProject.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"


extern "C" __declspec(dllexport) int __stdcall add(int a, int b)
{
	return a + b;
}