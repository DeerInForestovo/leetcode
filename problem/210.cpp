#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : graph[u]) {
                --in_degree[v];
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }
        if (order.size() != numCourses)
            return {};
        return order;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif