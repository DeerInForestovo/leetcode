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
    inline bool isVowel(char c) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    inline bool isConsonant(char c) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        return (c >= 'a' && c <= 'z') && !isVowel(c);
    }
    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    bool isValid(string word) {
        int length = word.length();
        if (length < 3) return false;
        bool atLeastOneVowel = false;
        bool atLeastOneConsonant = false;
        for (int i = 0; i < length; ++i)
            if (isVowel(word[i])) atLeastOneVowel = true;
                else if (isConsonant(word[i])) atLeastOneConsonant = true;
                    else if (!isDigit(word[i])) return false;
        return atLeastOneVowel && atLeastOneConsonant;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif