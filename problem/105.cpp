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
    TreeNode* solve(const vector<int>& preorder, const vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndexInInorder = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, rootVal) - inorder.begin();
        int leftSize = rootIndexInInorder - inStart;
        
        root->left = solve(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndexInInorder - 1);
        root->right = solve(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndexInInorder + 1, inEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif