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
    string simplifyPath(string path) {
        stack<string> stk;
        string token;
        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (token == "..") {
                    if (!stk.empty()) stk.pop();
                } else if (!token.empty() && token != ".") {
                    stk.push(token);
                }
                token.clear();
            } else {
                token += path[i];
            }
        }
        string result;
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        return result.empty() ? "/" : result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif