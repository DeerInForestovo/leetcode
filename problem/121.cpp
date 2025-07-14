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
        int lmin = prices[0], maxans = 0, psize = prices.size();
        for (int i = 1; i < psize; ++i) {
            maxans = max(prices[i] - lmin, maxans);
            lmin = min(prices[i], lmin);
        }
        return maxans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif