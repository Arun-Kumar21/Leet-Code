/*
Q2486. Append Characters to String to Make Subsequence
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        // Traverse through both strings
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                j++; // Move to the next character in t
            }
            i++; // Always move to the next character in s
        }

        // The number of characters to append is the number of characters left in t
        return t.length() - j;
    }
};
