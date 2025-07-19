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

class Solution {
public:
    struct TrieNode {
        bool is_end;
        TrieNode* children[27];
        TrieNode() : is_end(false) {
            memset(children, 0, sizeof(children));
        }
        void insert(const string& s) {
            TrieNode* node = this;
            for (char c : s) {
                int idx = c == '/' ? 26 : c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->is_end = true;
        }
        void get_res(vector<string>& res, string& path) {
            if (is_end) res.push_back(path);
            for (int i = 0; i < (27 - (int)is_end); ++i) {
                if (children[i]) {
                    char c = i == 26 ? '/' : 'a' + i;
                    path.push_back(c);
                    children[i]->get_res(res, path);
                    path.pop_back();
                }
            }
        }
    };
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        TrieNode root;
        for (const string& f : folder)
            root.insert(f);
        string str = "";
        root.get_res(res, str);
        return res;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif