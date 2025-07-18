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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, rootVal) - inorder.begin();
        int leftSize = rootIndex - inStart;
        
        root->left = solve(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
        root->right = solve(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif