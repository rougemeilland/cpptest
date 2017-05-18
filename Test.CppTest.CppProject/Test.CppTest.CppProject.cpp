// Test.CppTest.CppProject.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"


extern "C" __declspec(dllexport) int __stdcall add(int a, int b)
{
	return a + b;
}