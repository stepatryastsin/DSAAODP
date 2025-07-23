#ifndef REVERSE_INTEGER_H
#define REVERSE_INTEGER_H
//https://leetcode.com/problems/reverse-integer/description/
#include<limits>
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while (x != 0) {
            if (std::numeric_limits<int>::max() < ret * 10 + x % 10 ||
                std::numeric_limits<int>::min() > ret * 10 + x % 10) {
                return 0;
            }
            else {
                ret = ret * 10 + x % 10;
            }
            x = x / 10;
        }
        return ret;
    }
};
#endif // REVERSE_INTEGER_H