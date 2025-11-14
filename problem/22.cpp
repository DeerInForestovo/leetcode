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
    void dfs(int left, int right, string& current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        if (left > 0) {
            current.push_back('(');
            dfs(left - 1, right, current, result);
            current.pop_back();
        }
        if (right > left) {
            current.push_back(')');
            dfs(left, right - 1, current, result);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        dfs(n, n, current, result);
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