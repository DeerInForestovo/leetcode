#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, int> idx;
        int id = 0;
        for (const auto& eq : equations) {
            if (!idx.count(eq[0])) idx[eq[0]] = id++;
            if (!idx.count(eq[1])) idx[eq[1]] = id++;
        }
        vector<vector<pair<int, double>>> graph(id);
        for (int i = 0; i < n; ++i) {
            int u = idx[equations[i][0]], v = idx[equations[i][1]];
            double val = values[i];
            graph[u].emplace_back(v, val);
            graph[v].emplace_back(u, 1.0 / val);
        }
        vector<double> value(id, -1.0);
        vector<int> visited(id);  // component id
        int comp_id = 0;
        for (int i = 0; i < id; ++i) {
            if (visited[i]) continue;
            ++comp_id;
            value[i] = 1.0;
            visited[i] = comp_id;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (const auto& node: graph[u]) {
                    int v = node.first;
                    double val = node.second;
                    if (visited[v]) continue;
                    value[v] = value[u] / val;
                    visited[v] = comp_id;
                    q.push(v);
                }
            }
        }
        vector<double> result;
        for (const auto& q : queries) {
            if (!idx.count(q[0]) || !idx.count(q[1]) || visited[idx[q[0]]] != visited[idx[q[1]]])
                result.push_back(-1.0);
            else
                result.push_back(value[idx[q[0]]] / value[idx[q[1]]]);
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