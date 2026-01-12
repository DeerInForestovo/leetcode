#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> len1, len2;
        len1.resize(n);
        len2.resize(n);
        len1[0] = 1;
        len2[0] = 1;
        for (int i = 1; i < n; ++i) {
            len1[i] = 1;
            if (nums1[i] >= nums1[i - 1])
                len1[i] = max(len1[i], len1[i - 1] + 1);
            if (nums1[i] >= nums2[i - 1])
                len1[i] = max(len1[i], len2[i - 1] + 1);
            len2[i] = 1;
            if (nums2[i] >= nums2[i - 1])
                len2[i] = max(len2[i], len2[i - 1] + 1);
            if (nums2[i] >= nums1[i - 1])
                len2[i] = max(len2[i], len1[i - 1] + 1);
        }
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result = max(result, len1[i]);
            result = max(result, len2[i]);
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