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
    bool isalnum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome(string s) {
        int lp = 0, rp = s.size() - 1;
        while (lp < rp) {
            while (lp < rp && !isalnum(s[lp])) ++lp;
            while (lp < rp && !isalnum(s[rp])) --rp;
            if (tolower(s[lp]) != tolower(s[rp])) return false;
            ++lp;
            --rp;
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