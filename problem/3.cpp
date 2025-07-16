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
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), left = 0, right = 0, maxLength = 0;
        bool charSet[256] = {false};
        for (right = 0; right < n; ++right) {
            while (charSet[s[right]]) {
                charSet[s[left]] = false;
                left++;
            }
            charSet[s[right]] = true;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif