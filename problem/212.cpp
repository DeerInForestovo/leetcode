#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
    int n, m;
    vector<vector<bool>> vis;
    bool dfs(int x, int y, int pos, int sz, const string& word, const vector<vector<char>> &board) {
        if (pos == sz) return true;
        vis[x][y] = true;
        bool flag = false;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx == -1 || ty == -1 || tx == n || ty == m) continue;
            if (board[tx][ty] == word[pos] && !vis[tx][ty]) {
                if (dfs(tx, ty, pos + 1, sz, word, board)) {
                    flag = true;
                    break;
                }
            }
        }
        vis[x][y] = false;
        return flag;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++i)
            vis.push_back(vector<bool>(m, false));
        for (const auto &w: words) {
            bool flag = false;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == w[0])
                        if (dfs(i, j, 1, w.length(), w, board)) {
                            flag = true;
                            break;
                        }
                }
            if (flag) result.push_back(w);
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif