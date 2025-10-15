#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<pair<int, int>> cur;
    bool flag;
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int n = board.size(), m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m) {
            flag = false;
            return;
        }
        if (board[x][y] == 'X' || visited[x][y]) return;
        visited[x][y] = true;
        cur.push_back({x, y});
        dfs(x + 1, y, board, visited);
        dfs(x - 1, y, board, visited);
        dfs(x, y + 1, board, visited);
        dfs(x, y - 1, board, visited);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        cur = {};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == 'O' && !visited[i][j]) {
                    cur.clear();
                    flag = true;
                    dfs(i, j, board, visited);
                    if (flag)
                        for (auto& p : cur)
                            board[p.first][p.second] = 'X';
                }
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif