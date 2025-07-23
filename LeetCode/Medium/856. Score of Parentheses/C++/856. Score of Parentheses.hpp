#ifndef TASK856_H
#define TASK856_H
//https://leetcode.com/problems/score-of-parentheses/
#include<string>
#include<stack>
class Solution {
public:
    int scoreOfParentheses(const std::string& s) {
        std::stack<char> st;
        int ret = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push('(');
            }
            else {
                if (!st.empty() && s[i - 1] == '(') {
                    st.pop();
                    ret += (1 << static_cast<int>(st.size()));
                }
                else {
                    if (!st.empty()) st.pop();
                }
            }
        }

        return ret;
    }
};
#endif // !TASK856_H