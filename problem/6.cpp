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
    string convert(string s, int numRows) {
        string result;
        if (numRows <= 1 || numRows >= s.size()) return s;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += 2 * (numRows - 1)) {
                    result += s[j];
                }
            } else {
                int step1 = 2 * (numRows - 1 - i);
                int step2 = 2 * i;
                for (int j = i; j < s.size(); ) {
                    result += s[j];
                    j += step1;
                    if (j < s.size()) {
                        result += s[j];
                        j += step2;
                    }
                }
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