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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; ++i) {
            int traget = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = n - 1; j < k; ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                int sum = nums[j] + nums[k];
                if (sum < traget) ++j;
                    else if (sum > traget) --k;
                        else {
                            result.push_back({nums[i], nums[j], nums[k]});
                            while (j < k && nums[j] == nums[j + 1]) ++j;
                            while (j < k && nums[k] == nums[k - 1]) --k;
                            ++j; --k;
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