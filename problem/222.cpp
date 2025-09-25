#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool check(TreeNode* node, int id, int high_bit, int ans) {
        if (!node) return false;
        if (id == ans) return true;
        high_bit >>= 1;
        if (ans & high_bit) return check(node->right, id << 1 | 1, high_bit, ans);
            else return check(node->left, id << 1, high_bit, ans);
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l = 1, r = 50001;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int high_bit = 1;
            while ((high_bit << 1) <= mid) high_bit <<= 1;
            if (check(root, 1, high_bit, mid)) l = mid;
                else r = mid - 1;
        }
        return l;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    cout << sol.countNodes(nullptr) << endl; // Expected output: 0
    return 0;
}
#endif