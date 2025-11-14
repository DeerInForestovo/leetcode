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
    void dfs(int n, int row, vector<bool>& columns, vector<bool>& diagonals, vector<bool>& antiDiagonals, int& count) {
        if (row == n) {
            ++count;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (columns[col] || diagonals[row - col + n - 1] || antiDiagonals[row + col])
                continue;
            columns[col] = diagonals[row - col + n - 1] = antiDiagonals[row + col] = true;
            dfs(n, row + 1, columns, diagonals, antiDiagonals, count);
            columns[col] = diagonals[row - col + n - 1] = antiDiagonals[row + col] = false;
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> columns(n, false);
        vector<bool> diagonals(2 * n - 1, false);
        vector<bool> antiDiagonals(2 * n - 1, false);
        dfs(n, 0, columns, diagonals, antiDiagonals, count);
        return count;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif