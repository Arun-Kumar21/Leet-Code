/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.
*/

#include <iostream>
#include <string>
#include "../../../usr/include/c++/11/bits/algorithmfwd.h"
using namespace std;

class Solution
{
public:
  string reversePrefix(string word, char ch)
  {

    // Getting position of ch in word
    int charPos = word.find(ch);
    string reversingPart = "";

    // Checking ch exist in word or not
    if (charPos >= word.length())
      return word;

    for (int i = 0; i < word.length(); i++)
    {

      //  adding reverse part in new string
      if (word[i] == ch)
      {
        reversingPart += ch;
        break;
      }

      reversingPart += word[i];
    }

    // reversing new string
    reverse(reversingPart.begin(), reversingPart.end());

    // filling remaining elements in string
    for (int i = charPos + 1; i < word.length(); i++)
    {
      reversingPart += word[i];
    }

    return reversingPart;
  }
};

/*
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
*/