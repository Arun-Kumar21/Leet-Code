/*
300. Longest Increasing Subsequence
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int N = nums.size();
        vector<int> LIS(N, 1);

        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        int maxLength = 1;
        for (int i = 0; i < N; i++) {
            maxLength = max(maxLength, LIS[i]);
        }

        return maxLength;
    }
};
