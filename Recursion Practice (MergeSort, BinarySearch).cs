using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Recursion_Practice
{
    class Program
    {
        static int arrSize = 1000000;
        static int arrSizeMul = 4;
        static Random rnd = new Random();

        static void Main(string[] args)
        {
            List<int> arr = GenerateArr();
            List<int> sorted = MergeSort(arr);
            //PrintList(ref sorted);

            int needle;
            while ((needle = NextInput()) >= 0)
            {
                Console.WriteLine("Is " + needle + " in the array?  Answer: " + BinarySearch(sorted, needle));
                Console.WriteLine("Is " + needle + " in the array?  At index: " + BinarySearch(ref sorted, needle, 0, sorted.Count));
            }
        }


        static int NextInput()
        {
            Console.Write("Enter integer to search, any non-integer to quit: ");
            string line = Console.ReadLine();
            int number;

            try
            {
                number = Convert.ToInt32(line);
            }
            catch (Exception)   //FormatException || OverflowException || etc
            {
                number = -1;
            }

            return number;
        }



        static List<int> GenerateArr()
        {
            List<int> arr = new List<int>(arrSize);
            for (int i = 0; i < arrSize; i++)
            {
                arr.Add(rnd.Next(arrSize * arrSizeMul));
            }
            return arr;
        }


        /*
         * Recursive Binary Search (true/false)
         * Log(n) time complexity
         * Returns true if found, false is not found
         */
        static bool BinarySearch(List<int> arr, int needle)
        {
            if (arr.Count > 0)
            {
                //PrintList(ref arr);

                int middle = arr.Count / 2;

                if (arr[middle] < needle)
                {
                    //search right side
                    return BinarySearch(arr.GetRange(middle + 1, arr.Count - middle - 1), needle);
                }
                else if (arr[middle] > needle)
                {
                    //search left side
                    return BinarySearch(arr.GetRange(0, middle), needle);
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }


        /*
         * Recursive Binary Search (for index)
         * Log(n) time complexity
         * Returns array index (0 to n-1) if found, returns -1 if not found
         */
        static int BinarySearch(ref List<int> arr, int needle, int start, int end)
        {
            if (start < end)
            {
                //PrintListBetween(ref arr, start, end);

                int middle = (start + end) / 2;

                if (arr[middle] < needle)
                {
                    //search right side
                    return BinarySearch(ref arr, needle, middle + 1, end);
                }
                else if (arr[middle] > needle)
                {
                    //search left side
                    return BinarySearch(ref arr, needle, start, middle);
                }
                else
                {
                    return middle;
                }
            }
            else
            {
                return -1;
            }
        }


        /*
         * Recursive Merge Sort
         * n*Log(n) time complexity
         */
        static List<int> MergeSort(List<int> arr)
        {
            if (arr.Count > 1)
            {
                int middle = arr.Count / 2;

                List<int> left = MergeSort(arr.GetRange(0, middle));  //sort left side
                List<int> right = MergeSort(arr.GetRange(middle, arr.Count - middle));  //sort right side

                return Merge(left, right);
            }
            else  //if there's only one (or zero) element in array, it's considered sorted
            {
                return arr;
            }
        }


        /*
         * Merges two ordered List<int>s
         * Merges ascending - smallest to biggest, left to right
         */
        static List<int> Merge(List<int> left, List<int> right)
        {
            List<int> merged = new List<int>();

            int lc = 0;
            int rc = 0;

            while (lc < left.Count || rc < right.Count)
            {
                if (lc >= left.Count)
                {
                    merged.Add(right[rc]);
                    rc++;
                }
                else if (rc >= right.Count)
                {
                    merged.Add(left[lc]);
                    lc++;
                }
                else if (left[lc] < right[rc])
                {
                    merged.Add(left[lc]);
                    lc++;
                }
                else
                {
                    merged.Add(right[rc]);
                    rc++;
                }
            }

            return merged;
        }


        static void PrintList(ref List<int> arr)
        {
            for (int i = 0; i < arr.Count; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine("----------------------");
        }


        static void PrintListBetween(ref List<int> arr, int start, int end)
        {
            for (int i = start; i < end; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine("----------------------");
        }
    }
}
