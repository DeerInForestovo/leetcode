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
    bool isSubsequence(string s, string t) {
        int s_ind = 0, t_ind = 0, s_size = s.size(), t_size = t.size();
        while (s_ind < s_size && t_ind < t_size) {
            if (s[s_ind] == t[t_ind]) ++s_ind;
            ++t_ind;
        }
        return s_ind == s_size;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif