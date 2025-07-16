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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0;
        vector<int> result;
        for (int i = 0; i < (min(m, n) + 1) / 2; ++i) {
            for (int j = i; j < m - i; ++j) result.push_back(matrix[i][j]);
            for (int j = i + 1; j < n - i; ++j) result.push_back(matrix[j][m - i - 1]);
            if (n - i - 1 > i)
                for (int j = m - i - 2; j >= i; --j)
                    result.push_back(matrix[n - i - 1][j]);
            if (m - i - 1 > i)
                for (int j = n - i - 2; j > i; --j)
                    result.push_back(matrix[j][i]);
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