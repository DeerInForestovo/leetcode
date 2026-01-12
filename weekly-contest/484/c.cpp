#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    long long countPairs(vector<string>& words) {
        vector<string> transformed_words;
        for (auto& word : words) {
            string transformed;
            int n = word.size();
            for (int i = 1; i < n; ++i)
                transformed += (char)((word[i] - word[i - 1] + 26) % 26 + 128);
            transformed_words.push_back(transformed);
        }
        sort(transformed_words.begin(), transformed_words.end());
        long long result = 0;
        for (int i = 0, j; i < transformed_words.size(); i = j) {
            j = i + 1;
            while (j < transformed_words.size() && transformed_words[j] == transformed_words[i]) ++j;
            long long count = j - i;
            result += count * (count - 1) / 2;
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif