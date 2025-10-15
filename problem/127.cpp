#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool edge(int a, int b, vector<string>& wordList) {
        if (a == b) return false;
        int n = wordList[0].length(), dif = 0;
        for (int i = 0; i < n; ++i)
            if (wordList[a][i] != wordList[b][i])
                ++dif;
        return dif == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int sz = wordList.size(), s = sz - 1, t = -1;
        for (int j = 0; j < sz; ++j) {
            int n = wordList[0].length(), dif = 0;
            for (int i = 0; i < n; ++i)
                if (wordList[j][i] != endWord[i])
                    ++dif;
            if (dif == 0) {
                t = j;
                break;
            }
        }
        if (t == -1) return 0;
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
                if (dist[i] == -1 && edge(nod, i, wordList)) {
                    dist[i] = dist[nod] + 1;
                    q.push(i);
                }
            }
        }
        return dist[t] + 1;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif