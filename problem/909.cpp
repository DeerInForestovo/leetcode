#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> g;
        g.resize(n * n + 1);
        reverse(board.begin(), board.end());
        for (int i = 1; i < n; i += 2)
            reverse(board[i].begin(), board[i].end());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int u = i * n + j + 1;
                for (int k = 1; k <= 6; ++k) {
                    if (u + k > n * n) break;
                    int v = board[(u + k - 1) / n][(u + k - 1) % n];
                    if (v == -1) v = u + k;
                    g[u].push_back(v);
                }
            }
        vector<int> dist(n * n + 1, -1); dist[1] = 0;
        queue<int> q; q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (dist[v] != -1) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return dist[n * n];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    return 0;
}
#endif