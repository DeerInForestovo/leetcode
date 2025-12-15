#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0;
        long long last_len = 1;
        int last_price = -1;
        for (auto price: prices) {
            if (last_price == price + 1) {
                ++last_len;
            } else {
                last_len = 1;
            }
            result += last_len;
            last_price = price;
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif