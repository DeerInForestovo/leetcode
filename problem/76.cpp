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
- Use ++i instead of i++ if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size(), t_len = t.size(), satisfied = 0;
        const unsigned int max_char = 128;
        int s_count[max_char] = {0}, t_count[max_char] = {0};
        for (char c : t) t_count[c]++;
        for (int i = 0; i < max_char; ++i)
            if (t_count[i] == 0)
                ++satisfied;
        int l = -1, r, min_len = INT_MAX, start = 0;
        for (r = 0; r < s_len; ++r) {
            if (++s_count[s[r]] == t_count[s[r]]) ++satisfied;
            while (l < r && s_count[s[l + 1]] > t_count[s[l + 1]]) {
                ++l;
                --s_count[s[l]];
            }
            if (satisfied == max_char && r - l < min_len) {
                min_len = r - l;
                start = l + 1;
            }
        }
        if (min_len == INT_MAX) return "";
        return s.substr(start, min_len);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif