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
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        char mapping[256] = {0};
        bitset <256> used;
        bitset <256> mapped;

        for (int i = 0; i < s.size(); ++i) {
            char cs = s[i], ct = t[i];
            if (mapped[cs]) {
                if (mapping[cs] != ct) return false;
            } else {
                if (used[ct]) return false;
                mapping[cs] = ct;
                mapped[cs] = used[ct] = true;
            }
        }
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