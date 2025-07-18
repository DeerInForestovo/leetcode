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
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char c : magazine)
            ++cnt[c - 'a'];
        for (char c : ransomNote)
            --cnt[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i] < 0)
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