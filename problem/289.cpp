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
- Use ++i instead of i++ if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int liveNeighbors = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && (board[ni][nj] & 1))
                        ++liveNeighbors;
                }
                if (board[i][j] & 1) { // Current cell is alive
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                        board[i][j] |= 2; // Set to dead
                } else { // Current cell is dead
                    if (liveNeighbors == 3)
                        board[i][j] |= 4; // Set to alive
                }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] & 2) // Was alive, now dead
                    board[i][j] = 0;
                else if (board[i][j] & 4) // Was dead, now alive
                    board[i][j] = 1;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif