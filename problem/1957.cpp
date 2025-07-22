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
    string makeFancyString(string s) {
        string result;
        int count = 0;
        char prev_char = '\0';
        for (char c : s) {
            if (c == prev_char) {
                ++count;
            } else {
                count = 1;
                prev_char = c;
            }
            if (count < 3) {
                result += c;
            }
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