#include <bits/stdc++.h>
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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        for (auto neighbor : node->neighbors) {
            if (mp.find(neighbor) == mp.end()) {
                mp[neighbor] = new Node(neighbor->val);
                dfs(neighbor, mp);
            }
            mp[node]->neighbors.push_back(mp[neighbor]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        dfs(node, mp);
        return mp[node];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif