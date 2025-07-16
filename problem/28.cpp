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
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next(m, -1);
        for (int i = 1, j = -1; i < m; ++i) {
            while (j >= 0 && needle[i] != needle[j + 1]) j = next[j];
            if (needle[i] == needle[j + 1]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = -1; i < n; ++i) {
            while (j >= 0 && haystack[i] != needle[j + 1]) j = next[j];
            if (haystack[i] == needle[j + 1]) ++j;
            if (j == m - 1) return i - m + 1;
        }
        return -1;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif