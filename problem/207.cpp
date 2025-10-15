#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt = 0;
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            ++in_degree[pre[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (in_degree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++cnt;
            for (int v : graph[u]) {
                --in_degree[v];
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }
        return cnt == numCourses;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif