#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    // trie
    static int charToNum(char c) {
        // lower or upper
        if (c >= 'a' && c <= 'z') return c - 'a';
        return c - 'A' + 26;
    }
    struct TrieNode {
        TrieNode* next[52];
        int isEnd;  // id
        int size;
        TrieNode() {
            memset(next, 0, sizeof(next));
            isEnd = -1;
            size = 0;
        }
        void insert(const string& word, int id) {
            TrieNode* node = this;
            for (char c: word) {
                int idx = charToNum(c);
                if (!node->next[idx]) node->next[idx] = new TrieNode();
                node = node->next[idx];
                node->size++;
            }
            node->isEnd = id;
        }
        void remove(const string& word) {
            TrieNode* node = this;
            for (char c: word) {
                int idx = charToNum(c);
                if (!node->next[idx]) return;
                node = node->next[idx];
                node->size--;
            }
            node->isEnd = -1;
        }
    };
    TrieNode* root = new TrieNode();
    const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
    void dfs(int x, int y, int n, int m, TrieNode* cur, vector<vector<bool>>& vis, vector<string>& result, const vector<vector<char>>& board, const vector<string>& words) {
        if (cur->isEnd != -1) {
            result.push_back(words[cur->isEnd]);
            root->remove(words[cur->isEnd]);
        }
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            char c = board[nx][ny];
            int idx = charToNum(c);
            if (!cur->next[idx] || cur->next[idx]->size == 0) continue;
            dfs(nx, ny, n, m, cur->next[idx], vis, result, board, words);
        }
        vis[x][y] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<string> words = {word};
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<string> result;
        int cnt = 0;
        for (auto word: words)
            root->insert(word, cnt++);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                char c = board[i][j];
                int idx = charToNum(c);
                if (root->next[idx] && root->next[idx]->size > 0) {
                    vis[i][j] = true;
                    dfs(i, j, n, m, root->next[idx], vis, result, board, words);
                    vis[i][j] = false;
                }
            }
        return result.size() > 0;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif