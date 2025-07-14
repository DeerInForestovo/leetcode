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
    int maxProfit(vector<int>& prices) {
        int p0 = 0, p1 = -prices[0], psize = prices.size();
        for (int i = 1; i < psize; ++i) {
            p0 = max(p0, p1 + prices[i]);
            p1 = max(p1, p0 - prices[i]);
        }
        return max(p0, p1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif