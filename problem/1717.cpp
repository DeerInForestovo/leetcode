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

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.
*/

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        s = s + 'c';
        int score = 0, a = 0, b = 0;
        for (int i = 0; i <= n; ++i)
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') {
                if (a > 0) {
                    a--;
                    score += x;
                } else b++;
            } else {
                score += min(a, b) * y;
                a = b = 0;
            }
        return score;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif