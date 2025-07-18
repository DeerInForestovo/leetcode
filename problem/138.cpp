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

#ifdef LEETCODE_LOCAL
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        while (cur) {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node *ans = head->next;
        cur = head;
        while (cur) {
            Node *ano = cur->next;
            cur->next = ano->next;
            cur = cur->next;
            ano->next = (cur) ? cur->next : nullptr;
        }
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    int vals[] = {7, 13, 11, 10, 1};
    Node *node_ptrs[5];
    for (int i = 0; i < 5; ++i) {
        node_ptrs[i] = new Node(vals[i]);
        if (i > 0) node_ptrs[i - 1]->next = node_ptrs[i];
    }
    node_ptrs[1]->random = node_ptrs[0]; // 13 -> 7
    node_ptrs[2]->random = node_ptrs[4]; // 11 -> 1
    node_ptrs[3]->random = node_ptrs[2]; // 10 -> 11
    node_ptrs[4]->random = node_ptrs[0]; // 1 -> 7
    Node *ans = sol.copyRandomList(node_ptrs[0]);
    // Output the copied list
    Node *cur = ans;
    while (cur) {
        cout << "Node val: " << cur->val;
        if (cur->random) {
            cout << ", Random points to: " << cur->random->val;
        } else {
            cout << ", Random points to: null";
        }
        cout << endl;
        cur = cur->next;
    }
    return 0;
}
#endif