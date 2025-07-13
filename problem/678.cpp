#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        bitset<128> bs;
        bs[0] = true;
        for (char c: s) switch (c) {
            case '(': bs <<= 1; break;
            case ')': bs >>= 1; break;
            default: bs |= (bs << 1) | (bs >> 1);
        }
        return bs[0];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.checkValidString("(*))");
    return 0;
}
#endif