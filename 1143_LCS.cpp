/*
Q1143. Longest Common Subsequence
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> LCS(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    LCS[i][j] = 1 + LCS[i - 1][j - 1];
                } else {
                    LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
                }
            }
        }

        return LCS[m][n];
    }
};
