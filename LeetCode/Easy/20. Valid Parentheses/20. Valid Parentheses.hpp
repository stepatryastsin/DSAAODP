#ifndef TASK20_HPP
#define TASK20_HPP
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (const auto& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            else {
                if (stack.empty()) return false;

                if ((stack.top() == '(' && ch == ')') ||
                    (stack.top() == '[' && ch == ']') ||
                    (stack.top() == '{' && ch == '}')) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
#endif // !TASK20_HPP
