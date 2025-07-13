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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // O(1) memory
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int i = m + n - 1;
        auto p1 = nums1.begin() + m, p2 = nums2.end();
        while (true) {
            if (*(p2 - 1) > *(p1 - 1)) {
                nums1[i--] = *--p2;
                if (p2 == nums2.begin()) break;
            } else {
                nums1[i--] = *--p1;
                if (p1 == nums1.begin()) break;
            }
        }
        if (p2 != nums2.begin())
            do {
                nums1[i--] = *--p2;
            } while(p2 != nums2.begin());
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    vector<int> a;
    a.push_back(2);
    a.push_back(0);
    vector<int> b;
    b.push_back(1);
    sol.merge(a, 1, b, 1);
    cout << a[0] << ' ' << a[1] << endl;
    return 0;
}
#endif