using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBazz
{
    class Program
    {
        static IList<string> FizzBuzz(int n)
        {
            List<string> l = new List<string>();
            int i = 1;
            string cur = "";
            while(i <= n)
            {
                if (i % 3 == 0 && i % 5 == 0)
                    cur = "FizzBuzz";
                else if (i % 3 == 0){
                    cur = "Fizz";
                }
                else if (i % 5 == 0) {
                    cur = "Buzz";
                }
                else {
                    cur = i.ToString();
                }
                ++i;
                l.Add(cur);
            }
            return l;
        }
        static void Main(string[] args)
        {
            int n = 15;
            List<string> ll = FizzBuzz(n).ToList();
            for (int i = 0; i < n; ++i)
                Console.WriteLine(ll[i]);
            Console.ReadLine();
        }
    }
}
