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
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1;
        while (pos >= 0 && s[pos] == ' ') pos--;
        int pos2 = pos;
        while (pos2 >= 0 && s[pos2] != ' ') pos2--;
        return pos - pos2;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif