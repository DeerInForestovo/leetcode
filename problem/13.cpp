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
    int romanToInt(string s) {
        int romanMap[256] = {0};
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        
        int total = 0;
        int prevValue = 0;
        
        for (char c : s) {
            int currentValue = romanMap[c];
            if (currentValue > prevValue) total += currentValue - 2 * prevValue;
                else total += currentValue;
            prevValue = currentValue;
        }
        
        return total;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif