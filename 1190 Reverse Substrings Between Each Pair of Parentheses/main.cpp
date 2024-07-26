#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<pair<string, int>> st;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.emplace("", i);
            }
            else if (s[i] == ')' && !st.empty())
            {
                pair<string, int> elem = st.top();
                st.pop();

                string to_reverse = s.substr(elem.second + 1, i - elem.second - 1);
                reverse(to_reverse.begin(), to_reverse.end());
                s.replace(elem.second, i - elem.second + 1, to_reverse);
                i = elem.second + to_reverse.size() - 1;
            }
        }

        return s;
    }
};