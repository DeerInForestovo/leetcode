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
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(256, 0);
        for (char c : s) ++count[c];
        for (char c : t)
            if (--count[c] < 0)
                return false;
        return true;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif