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
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty()) return false;
                char top = stk.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif