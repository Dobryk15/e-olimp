using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KeyboardRow
{
    class Program
    {
        static string[] FindWords(string[] words)
        {
            List<string> l = new List<string>();
            Dictionary<char, int> d = new Dictionary<char, int>();
            string w = "";
            d.Add('A', 2);
            d.Add('S', 2);
            d.Add('D', 2);
            d.Add('F', 2);
            d.Add('G', 2);
            d.Add('H', 2);
            d.Add('J', 2);
            d.Add('K', 2);
            d.Add('L', 2);
            d.Add('a', 2);
            d.Add('s', 2);
            d.Add('d', 2);
            d.Add('f', 2);
            d.Add('g', 2);
            d.Add('h', 2);
            d.Add('j', 2);
            d.Add('k', 2);
            d.Add('l', 2);
            d.Add('Q', 1);
            d.Add('W', 1);
            d.Add('E', 1);
            d.Add('R', 1);
            d.Add('T', 1);
            d.Add('Y', 1);
            d.Add('U', 1);
            d.Add('I', 1);
            d.Add('O', 1);
            d.Add('P', 1);
            d.Add('q', 1);
            d.Add('w', 1);
            d.Add('e', 1);
            d.Add('r', 1);
            d.Add('t', 1);
            d.Add('y', 1);
            d.Add('u', 1);
            d.Add('i', 1);
            d.Add('o', 1);
            d.Add('p', 1);
           
            d.Add('M', 3);
            d.Add('N', 3);
            d.Add('B', 3);
            d.Add('V', 3);
            d.Add('C', 3);
            d.Add('X', 3);
            d.Add('Z', 3);

            d.Add('m', 3);
            d.Add('n', 3);
            d.Add('b', 3);
            d.Add('v', 3);
            d.Add('c', 3);
            d.Add('x', 3);
            d.Add('z', 3);
            //string[] res = new string[words.Length];
            for (int i = 0; i < words.Length; ++i)
            {
                w = words[i];
                int k = w.Length;
                int row = 0;
                row = d[w[k - 1]];
                while (k > 0)
                {
                    if (row != d[words[i][k - 1]])
                        k = -1;
                    else
                        row = d[words[i][k - 1]];
                    --k;
                }
                if (k >= 0)
                    l.Add(words[i]);
            }
            string[] res = new string[l.Count];
            for (int i = 0; i < l.Count; ++i)
                res[i] = l[i];
            return res;
        }

       
        static void Main(string[] args)
        {
            string[] a = new string[5];
            a[0] = "ddd";
            a[1] = "row";
            a[2] = "mum";
            a[3] = "rare";
            a[4] = "wow";
            string[] arr = FindWords(a);

            for (int i = 0; i < arr.Length; ++i)
                Console.WriteLine(arr[i]);
            Console.ReadLine();
        }
    }
}
