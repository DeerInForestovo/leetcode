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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        
        sort(citations.begin(), citations.end());
        int hIndex = 0;
        
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n - i) {
                hIndex = n - i;
                break;
            }
        }
        
        return hIndex;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif