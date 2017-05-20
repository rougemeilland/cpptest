using System;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test.CppTest.ConsoleApp
{
    class Program
    {
        static void Main()
        {
            var stab = new CppModuleStab();
            Console.WriteLine("2 + 3 = {0}", stab.Add(2, 3));
            var x = 0x123456789abcdef0UL;
            var y = 0x0fedcba987654321UL;
            ulong r_high;
            var r_low = stab.Mul64(x, y, out r_high);
            Console.WriteLine("0x{0:x16} * 0x{1:x16} = 0x{2:x16}{3:x16}", x, y, r_high, r_low);
            Console.WriteLine("0x{0:x16} * 0x{1:x16} = 0x{2:x32}", x, y, (new BigInteger(x) * new BigInteger(y)));
            Console.ReadLine();
        }
    }
}