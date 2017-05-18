using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.CppTest.ConsoleApp
{
    class Program
    {
        [DllImport("Test.CppTest.CppProject.dll")]
        static extern int add(int a, int b);

        static void Main()
        {
            Console.WriteLine("2 + 3 = {0}", add(2, 3));
            Console.WriteLine("4 + 5 = {0}", add(4, 5));
        }
    }
}
