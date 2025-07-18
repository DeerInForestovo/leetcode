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
class BSTIterator {
public:
    bool is_has_next;
    TreeNode* cur;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        if (!root) {
            is_has_next = false;
            return;
        }
        is_has_next = true;
        cur = root;
        while (cur->left) {
            st.push(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        int val = cur->val;
        // find next in advance
        if (cur->right) {
            st.push(cur);
            cur = cur->right;
            while (cur->left) {
                st.push(cur);
                cur = cur->left;
            }
        } else {
            TreeNode *next = nullptr;
            while (!st.empty()) {
                TreeNode *parrent = st.top();
                st.pop();
                if (parrent->left == cur) {
                    next = parrent;
                    break;
                }
                cur = parrent;
            }
            if (next) cur = next;
                else is_has_next = false;
        }
        return val;
    }
    
    bool hasNext() {
        return is_has_next;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif