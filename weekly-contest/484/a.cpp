#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.


You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters in the prefix is equal to len(prefix) % 3.

Return the count of residue prefixes in s.

A prefix of a string is a non-empty substring that starts from the beginning of the string and extends to any point within it.

*/



class Solution {
public:
    int residuePrefixes(string s) {
        int cnt = 0, distinct = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 1)
                distinct++;
            if (distinct == (i + 1) % 3)
                cnt++;
        }
        return cnt;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif