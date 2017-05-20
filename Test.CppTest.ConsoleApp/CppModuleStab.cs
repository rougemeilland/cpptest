using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Test.CppTest.ConsoleApp
{
    internal class CppModuleStab
    {
        [DllImport("kernel32", SetLastError = true)]
        private static extern bool SetDllDirectory(string lpPathName);

        [DllImport("Test.CppTest.CppProject.dll")]
        static extern int UM_Add(int x, int y);

        [DllImport("Test.CppTest.CppProject.dll")]
        static extern UInt64 UM_Mul64(UInt64 x, UInt64 y, out UInt64 high_part);

        [DllImport("Test.CppTest.CppProject.dll")]
        static extern bool UM_Initialize();

        static CppModuleStab()
        {
            var base_dir = Path.GetDirectoryName(typeof(CppModuleStab).Assembly.Location);
            switch (IntPtr.Size * 8)
            {
                case 64:
                    SetDllDirectory(Path.Combine(base_dir, "x64"));
                    break;
                case 32:
                    SetDllDirectory(Path.Combine(base_dir, "x86"));
                    break;
                default:
                    throw new PlatformNotSupportedException();
            }
            if (!UM_Initialize())
                throw new PlatformNotSupportedException();
        }

        public int Add(int x, int y)
        {
            return (UM_Add(x, y));
        }

        public ulong Mul64(ulong x, ulong y, out ulong high_part)
        {
            return (UM_Mul64(x, y, out high_part));
        }
    }
}