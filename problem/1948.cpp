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
    struct Trie {
        map<string, Trie*> children;
        string sign;
    };
    Trie* root;
    void insertPath(const vector<string>& path) {
        Trie* node = root;
        for (const string& dir : path) {
            if (!node->children.count(dir)) {
                node->children[dir] = new Trie();
            }
            node = node->children[dir];
        }
    }
    string dfs(Trie* node, map<string, int>& count) {
        node->sign = "";
        for (auto& [dir, child] : node->children) {
            node->sign += dir + "(" + dfs(child, count) + ")";
        }
        count[node->sign]++;
        // cout << node->sign << endl;
        return node->sign;
    }
    void dfs2(Trie* node, map<string, int>& count, vector<string>& path, vector<vector<string>>& result) {
        if (count[node->sign] > 1) return; // Skip if this path is not unique
        if (path.size()) result.push_back(path);
        for (auto& [dir, child] : node->children) {
            path.push_back(dir);
            dfs2(child, count, path, result);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new Trie();
        for (auto &path: paths) {
            insertPath(path);
        }
        map<string, int> count;
        dfs(root, count);
        count[""] = 0; // Ensure the root path is not counted
        vector<vector<string>> result;
        vector<string> path;
        dfs2(root, count, path, result);
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
    vector<vector<string>> paths = {{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}};
    vector<vector<string>> result = sol.deleteDuplicateFolder(paths);
    for (const auto& path : result) {
        cout << "[";
        for (const auto& dir : path) {
            cout << dir << " ";
        }
        cout << "]\n";
    }
    return 0;
}
#endif