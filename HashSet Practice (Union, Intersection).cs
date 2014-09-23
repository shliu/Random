using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication4
{
    class Program
    {
        static int size = 10;
        static int mult = 4;
        static Random rnd = new Random();


        static void Main(string[] args)
        {
            while (PromptContinue())
            {
                List<int> first = GenList();
                List<int> second = GenList();

                first.Sort();
                PrintList(first);
                second.Sort();
                PrintList(second);

                List<int> union = Union(first, second);
                List<int> intersect = Intersect(first, second);

                Console.WriteLine("union: ");
                union.Sort();
                PrintList(union);
                Console.WriteLine("intersect: ");
                intersect.Sort();
                PrintList(intersect);
            }
        }


        static bool PromptContinue()
        {
            Console.Write("Type \"g\" to run, any other key to quit: ");
            return Console.ReadLine() == "g";
        }


        static void PrintList(List<int> list)
        {
            string line = "";

            for (int i = 0; i < list.Count; i++)
            {
                line += list[i] + " ";
            }

            Console.WriteLine(line);
            Console.WriteLine("------------");
        }


        static List<int> GenList()
        {
            List<int> list = new List<int>();

            for (int i = 0; i < size; i++)
            {
                list.Add(rnd.Next(size*mult));
            }

            return list;
        }


        static List<int> Union(List<int> first, List<int> second)
        {
            HashSet<int> secondHash = new HashSet<int>();

            for (int i = 0; i < second.Count; i++)
            {
                secondHash.Add(second[i]);
            }

            for (int i = 0; i < first.Count; i++)
            {
                secondHash.Add(first[i]);
            }

            return secondHash.ToList<int>();
        }


        static List<int> Intersect(List<int> first, List<int> second)
        {
            HashSet<int> secondHash = new HashSet<int>();
            HashSet<int> intersect = new HashSet<int>();

            for (int i = 0; i < second.Count; i++)
            {
                secondHash.Add(second[i]);
            }

            for (int i = 0; i < first.Count; i++)
            {
                if (secondHash.Contains(first[i]))
                {
                    intersect.Add(first[i]);
                }
            }

            return intersect.ToList<int>();
        }
    }
}

