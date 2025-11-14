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
    int singleNumber(vector<int>& nums) {
        // only one number appears once, all others appear three times
        unsigned long long bits = 0; // use two bits to count the occurrences of each bit
        for (int num : nums) {
            unsigned int n = (unsigned int)num;
            for (int i = 0; i < 32; ++i) {
                if (n & 1) {
                    if (bits >> (2 * i + 1) & 1) {
                        bits &= ~(3ULL << (2 * i));
                    } else {
                        bits += (1ULL << (2 * i));
                    }
                }
                n >>= 1;
            }
        }
        unsigned int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits >> (2 * i) & 1) {
                result |= (1U << i);
            }
        }
        return (int)result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif