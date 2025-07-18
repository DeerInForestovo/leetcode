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
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (token == "+") stk.push(a + b);
                else if (token == "-") stk.push(a - b);
                else if (token == "*") stk.push(a * b);
                else if (token == "/") stk.push(a / b);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif