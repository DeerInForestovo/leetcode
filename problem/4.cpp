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
    inline int get(vector<int>& vec, int ind) {
        int l = (int)vec.size();
        return ind < 1 ? -(1 << 30) : (ind > l ? (1 << 30) : vec[ind - 1]);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int l1 = (int)nums1.size(), l2 = (int)nums2.size(), lt = l1 + l2 + 1 >> 1, inf = 1 << 30;
        int l = 0, r = l1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (get(nums1, mid) > get(nums2, lt - mid + 1)) r = mid - 1;
                else l = mid;
        }
        int ansl = max(get(nums1, l), get(nums2, lt - l));
        if ((l1 + l2) % 2 == 0) {
            int ansr = min(get(nums1, l + 1), get(nums2, lt - l + 1));
            return (ansl + ansr) / 2.0;
        } else return 1.0 * ansl;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif