#ifndef TASK2419_HPP
#define TASK2419_HPP
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int M = *std::max_element(nums.begin(), nums.end());

        std::pair<int, int> acc{ 0, 0 };

        std::for_each(nums.begin(), nums.end(), [&](int x) {
            if (x == M) {
                ++acc.first;
                acc.second = std::max(acc.second, acc.first);
            }
            else {
                acc.first = 0;
            }
            });

        return acc.second;
    }
};

#endif // !TASK_HPP
