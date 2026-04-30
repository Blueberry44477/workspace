namespace task1_cs.Models;

using System;
using System.Collections.Generic;
using System.Linq;
public static class LetterProcessor
{
    // Розмістити в списку L2 в алфавітному порядку всі літери, що 
    // входять у список L1 по одному разу, по декілька разів і не входять жодного разу.
    public static List<char> CreateList2(List<char> List1)
    {
        var alphabet = "abcdefghijklmnopqrstuvwxyz";
        var List2 = new List<char>();

        foreach (char letter in alphabet)
        {
            int count = List1.Count(x => x == letter);
            if (count == 1)
                List2.Add(letter);

            else if (count > 1)
            {
                for (int i = 0; i < count; i++)
                    List2.Add(letter);
            }

            else if (count == 0)
                List2.Add(letter); // not even once.
        }
        return List2.OrderBy(c => c).ToList();
    }
}