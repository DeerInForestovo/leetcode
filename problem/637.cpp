#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> tot, cnt;
    int maxdepth = 0;
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        maxdepth = max(maxdepth, depth);
        tot[depth] += node->val;
        ++cnt[depth];
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        tot.resize(10000);
        cnt.resize(10000);
        dfs(root, 0);
        vector<double> ans;
        for (int d = 0; d <= maxdepth; ++d)
            ans.push_back(tot[d] / cnt[d]);
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif