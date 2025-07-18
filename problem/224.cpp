#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // push 1 for +(...), -1 for -(...)
        int ans = 0, num = 0, sign = 1, global_sign = 1; // sign: 1 for '+', -1 for '-'
        for (char c: s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                ans += global_sign * sign * num;
                num = 0;
                sign = 1; // reset sign to '+'
            } else if (c == '-') {
                ans += global_sign * sign * num;
                num = 0;
                sign = -1; // reset sign to '-'
            } else if (c == '(') { // num = 0
                stk.push(sign);
                global_sign *= sign; // update global_sign
                sign = 1; // reset sign to '+'
            } else if (c == ')') {
                ans += global_sign * sign * num;
                num = 0;
                sign = stk.top(); // restore previous sign
                stk.pop();
                global_sign *= sign; // restore global_sign
            }
        }
        ans += global_sign * sign * num; // add the last number
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif