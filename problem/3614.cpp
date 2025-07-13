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
    char processStr(string s, long long k) {
        ++k;
        int s_len = s.length();
        vector<long long> len(s_len);  // length of string after i_th operation
        long long l = 0;
        for (int i = 0; i < s_len; ++i) {
            switch (s[i]) {
                case '*': l = max(0ll, l - 1); break;
                case '#': l <<= 1; break;
                case '%': break;
                default: ++l;
            }
            len[i] = l;
        }
        if (len[s_len - 1] < k) return '.';
        for (int i = s_len; i--; ) {
            long long cur_len = len[i];
            switch (s[i]) {
                case '*': break;
                case '#': if (k > (cur_len >> 1)) k -= (cur_len >> 1); break;
                case '%': k = cur_len + 1 - k; break;
                default: if (cur_len == k) return s[i];
            }
        }
        return '.';
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.processStr("a#b%*", 1) << endl;
    cout << sol.processStr("cd%#*#", 3) << endl;
    cout << sol.processStr("z*#", 0) << endl;
    return 0;
}
#endif