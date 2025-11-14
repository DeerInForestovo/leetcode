#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result(n);
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) result.insert(result.begin(), carry);
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