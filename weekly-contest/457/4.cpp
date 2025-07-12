#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int cnt = 0;
        while (true) {
            if (tx < sx || ty < sy) return -1;
            if (tx == sx && ty == sy) return cnt;
            ++cnt;
            if (tx > ty) {
                if (tx > (ty << 1 )) {
                    if (tx & 1) return -1;
                    tx >>= 1;
                } else tx -= ty;
            } else if (tx < ty) {
                if (ty > (tx << 1 )) {
                    if (ty & 1) return -1;
                    ty >>= 1;
                } else ty -= tx;
            } else {
                if (sx == 0) {
                    while (ty != sy) {
                        if (ty & 1) return -1;
                        ty >>= 1;
                        ++cnt;
                    }
                    return cnt;
                } else if (sy == 0) {
                    while (tx != sx) {
                        if (tx & 1) return -1;
                        tx >>= 1;
                        ++cnt;
                    }
                    return cnt;
                } else return -1;
            }
        }
    }
};

#ifdef LEETCODE_LOCAL
#include <iostream>
int main() {
    Solution sol;
    // Add test cases here
    return 0;
}
#endif