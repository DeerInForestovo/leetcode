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
    string reverseWords(string s) {
        int n = s.size() - 1;
        string result;
        while (n >= 0) {
            while (n >= 0 && s[n] == ' ') n--;
            if (n < 0) break;
            if (result.size() > 0) result += ' ';
            int end = n;
            while (n >= 0 && s[n] != ' ') n--;
            result += s.substr(n + 1, end - n);
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    cout << 1;
    Solution sol;
    // Add test cases here
    cout << sol.reverseWords("the sky is blue") << endl; // Output: "blue is sky the"
    cout << sol.reverseWords("  hello world  ") << endl; // Output: "world hello"
    return 0;
}
#endif