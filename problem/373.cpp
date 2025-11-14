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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;
        typedef pair<int, pair<int, int>> HeapNode; // -sum, (i, j)
        sort(nums2.begin(), nums2.end());
        priority_queue<HeapNode> q;
        for (int i = 0; i < nums1.size(); ++i)
            q.push({-(nums1[i] + nums2[0]), {i, 0}});
        while (k-- > 0 && !q.empty()) {
            auto node = q.top(); q.pop();
            int sum = -node.first;
            int i = node.second.first;
            int j = node.second.second;
            result.push_back({nums1[i], nums2[j]});
            ++j;
            if (j < nums2.size())
                q.push({-(nums1[i] + nums2[j]), {i, j}});
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