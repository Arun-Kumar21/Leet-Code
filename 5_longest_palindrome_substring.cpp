/*
Q5. Longest Palindromic Substring
*/

#include<bits/stdc++.h>
using namespace std;

/*
  Result into TLE

  Time complexity O(N^3)
*/

class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void utilPalindrome(const string& s, vector<vector<int>>& dp, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (isPalindrome(s.substr(i, j - i + 1))) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    string longestPalindrome(string s) {
        int N = s.length();
        if (N == 0) return "";

        vector<vector<int>> dp(N, vector<int>(N, 0));
        utilPalindrome(s, dp, N);

        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (dp[i][j] && (j - i + 1) > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

/*
  Time complexity -> O(N^2)
*/

class Solution2 {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        if (N == 0) return "";

        // Create a DP table to store palindrome information
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        int maxLength = 1;
        int start = 0;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < N; i++) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < N - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length greater than 2
        for (int length = 3; length <= N; length++) {
            for (int i = 0; i < N - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (length > maxLength) {
                        start = i;
                        maxLength = length;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};


int main() {
    Solution solution;
    string s = "babad";
    string longestPalindromicSubstring = solution.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring << endl;
    return 0;
}