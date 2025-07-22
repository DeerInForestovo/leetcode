#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool is_prime(int num) {
        if (num == 0 || num == 1) return false;
        int sqr = sqrt(num);
        for (int i = 2; i <= sqr; ++i)
            if (num % i == 0) return false;
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long ans = 0;
        int ns = nums.size();
        for (int i = 0; i < ns; ++i)
            if (is_prime(i)) ans += nums[i];
                else ans -= nums[i];
        return abs(ans);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    vector<int> num({-1,5,7,0});
    cout << sol.splitArray(num) << endl;
    return 0;
}
#endif