#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool edge(int a, int b, vector<string>& bank) {
        if (a == b) return false;
        int n = bank[0].length(), dif = 0;
        for (int i = 0; i < n; ++i)
            if (bank[a][i] != bank[b][i])
                ++dif;
        return dif == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.push_back(startGene);
        int sz = bank.size(), s = sz - 1, t = -1;
        for (int j = 0; j < sz; ++j) {
            int n = bank[0].length(), dif = 0;
            for (int i = 0; i < n; ++i)
                if (bank[j][i] != endGene[i])
                    ++dif;
            if (dif == 0) {
                t = j;
                break;
            }
        }
        if (t == -1) return -1;
        queue<int> q;
        vector<int> dist;
        for (int i = 0; i < sz; ++i)
            dist.push_back(-1);
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int nod = q.front();
            q.pop();
            for (int i = 0; i < sz; ++i) {
                if (dist[i] == -1 && edge(nod, i, bank)) {
                    dist[i] = dist[nod] + 1;
                    q.push(i);
                }
            }
        }
        return dist[t];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif