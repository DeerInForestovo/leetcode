#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

#define lowbit(x) ((x) & (-(x)))
class Solution {
public:
    static const int MAXN = 100010;
    int n;
    int BIT[MAXN];
    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= lowbit(idx))
            sum += BIT[idx];
        return sum;
    }
    void update(int idx, int val) {
        for (++idx; idx <= n; idx += lowbit(idx))
            BIT[idx] += val;
    }
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        vector<int> results;
        n = s.size();
        memset(BIT, 0, sizeof(BIT));
        for (int i = 1; i < n; ++i)
            if (s[i] == s[i - 1])
                update(i, 1);
        for (auto &q : queries) {
            int op = q[0];
            if (op == 1) {
                int i = q[1];
                if (i > 0) {
                    if (s[i] == s[i - 1]) update(i, -1);
                        else update(i, 1);
                }
                if (i + 1 < n) {
                    if (s[i] == s[i + 1]) update(i + 1, -1);
                        else update(i + 1, 1);
                }
                s[i] = 'A' + 'B' - s[i];
            } else {
                int l = q[1], r = q[2];
                results.push_back(query(r) - query(l));
            }
        }
        return results;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif