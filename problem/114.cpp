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
    TreeNode* dfs(TreeNode* root) { // Return the last node
        if (!root) return nullptr;
        TreeNode* leftLast = dfs(root->left);
        TreeNode* rightLast = dfs(root->right);
        if (leftLast) {
            leftLast->right = root->right; // Connect left subtree's last node to right subtree
            root->right = root->left; // Move left subtree to the right
            root->left = nullptr; // Set left child to nullptr
        }
        return rightLast ? rightLast : (leftLast ? leftLast : root); // Return the last node in the flattened tree
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif