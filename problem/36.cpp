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
    bool isValidSudoku(vector<vector<char>>& board) {
        short col[9] = {0}, box[3] = {0};
        for (char i = 0; i < 9; ++i) {
            short row = 0;
            for (char j = 0; j < 9; ++j) if (board[i][j] != '.') {
                short tag = 1 << (board[i][j] - '0');
                if (row & tag || col[j] & tag || box[j / 3] & tag) return false;
                row |= tag;
                col[j] |= tag;
                box[j / 3] |= tag;
            }
            if (i == 2 || i == 5) box[0] = box[1] = box[2] = 0;
        }
        return true;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif