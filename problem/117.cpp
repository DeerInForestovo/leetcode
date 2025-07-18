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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *cur_layer_head = root, *next_layer_head = nullptr, *next_layer_tail = nullptr;
        while (cur_layer_head) {
            Node *cur = cur_layer_head;
            while (cur) {
                if (cur->left) {
                    if (!next_layer_head) next_layer_head = cur->left;
                    if (next_layer_tail) next_layer_tail->next = cur->left;
                    next_layer_tail = cur->left;
                }
                if (cur->right) {
                    if (!next_layer_head) next_layer_head = cur->right;
                    if (next_layer_tail) next_layer_tail->next = cur->right;
                    next_layer_tail = cur->right;
                }
                cur = cur->next;
            }
            cur_layer_head = next_layer_head;
            next_layer_head = nullptr;
            next_layer_tail = nullptr;
        }
        return root;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif