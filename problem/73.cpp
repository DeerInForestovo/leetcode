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
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), zeroRow = -1, zeroCol;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == 0) {
                    if (zeroRow == -1) {
                        zeroRow = i;
                        zeroCol = j;
                    }
                    if (i != zeroRow)
                        matrix[i][zeroCol] = 0;
                    if (j != zeroCol)
                        matrix[zeroRow][j] = 0;
                }
        if (zeroRow != -1) {
            for (int i = 0; i < n; ++i)
                if (i != zeroRow)
                    for (int j = 0; j < m; ++j)
                        if (j != zeroCol && (matrix[i][zeroCol] == 0 || matrix[zeroRow][j] == 0))
                            matrix[i][j] = 0;
            for (int j = 0; j < m; ++j)
                matrix[zeroRow][j] = 0;
            for (int i = 0; i < n; ++i)
                matrix[i][zeroCol] = 0;
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