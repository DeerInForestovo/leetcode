#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int minAllOneMultiple(int k) {
        int mod = 1 % k, len = 1;
        std::unordered_set<int> seen;
        while (mod != 0) {
            if (seen.count(mod)) return -1;
            seen.insert(mod);
            mod = (mod * 10 + 1) % k;
            ++len;
        }
        return len;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif