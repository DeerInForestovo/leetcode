#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), m = 0;
        while (true) {
            if (strs[0].size() <= m) return strs[0].substr(0, m);
            char c = strs[0][m];
            for (int i = 1; i < n; ++i)
                if (strs[i].size() <= m || strs[i][m] != c) 
                    return strs[0].substr(0, m);
            ++m;
        }
        return "";
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif