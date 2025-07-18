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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif