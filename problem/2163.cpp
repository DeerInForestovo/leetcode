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
- Use variable_name instead of variableName for any variable name.
*/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> zero_break(n + 1, 0);
        priority_queue<long long> max_heap;
        long long sum = 0, min_ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            max_heap.push(nums[i]);
        }
        zero_break[0] = sum;
        for (int i = n; i < 2 * n; ++i) {
            sum += nums[i];
            max_heap.push(nums[i]);
            sum -= max_heap.top();
            max_heap.pop();
            zero_break[i - n + 1] = sum;
        }
        max_heap = priority_queue<long long>();
        sum = 0;
        for (int i = 2 * n; i < 3 * n; ++i) {
            sum += nums[i];
            max_heap.push(-nums[i]);
        }
        min_ans = zero_break[n] - sum;
        for (int i = 2 * n - 1; i >= n; --i) {
            sum += nums[i];
            max_heap.push(-nums[i]);
            sum += max_heap.top();
            max_heap.pop();
            min_ans = min(min_ans, zero_break[i - n] - sum);
        }
        return min_ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif