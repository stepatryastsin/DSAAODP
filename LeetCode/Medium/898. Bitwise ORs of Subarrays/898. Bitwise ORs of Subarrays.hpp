#ifndef TASK898_HPP
#define TASK898_HPP
class Solution {
public:
    int subarrayBitwiseORs(const std::vector<int>& arr) {
        int n = arr.size();
        std::unordered_set<int> uniqElem;
        std::unordered_set<int> prev, curr;
        prev.reserve(32);
        curr.reserve(32);
        uniqElem.reserve(n * 32);

        for (int i = 0; i < n; ++i) {
            curr.clear();

            curr.insert(arr[i]);

            for (int x : prev) {
                curr.insert(x | arr[i]);
            }

            for (int x : curr) {
                uniqElem.insert(x);
            }

            prev.swap(curr);
        }

        return uniqElem.size();
    }
};
#endif // !TASK898_HPP
