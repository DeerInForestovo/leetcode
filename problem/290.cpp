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
    bool wordPattern(string pattern, string s) {
        string word[26];
        int s_len = s.length(), p_len = pattern.length(), s_index = 0, p_index = 0;
        while (s_index < s_len && p_index < p_len) {
            int word_end = s.find(' ', s_index);
            if (word_end == string::npos) word_end = s_len;
            if (word[pattern[p_index] - 'a'].empty())
                word[pattern[p_index] - 'a'] = s.substr(s_index, word_end - s_index);
            else if (word[pattern[p_index] - 'a'] != s.substr(s_index, word_end - s_index))
                return false;
            s_index = word_end + 1;
            ++p_index;
        }
        if (s_index < s_len || p_index < p_len) return false;
        for (int i = 0; i < 26; ++i)
            if (!word[i].empty())
                for (int j = i + 1; j < 26; ++j)
                    if (word[i] == word[j]) return false;
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