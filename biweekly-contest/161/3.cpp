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
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    bool check(int n, vector<vector<pair<int, int>>>& to, vector<bool>& online, long long k, int mid) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto p = pq.top();
            auto d = p.first;
            auto u = p.second;
            pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : to[u]) {
                if (w <= mid) continue;
                if (dist[v] > dist[u] + w && online[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int l = -1, r = 1e9, mid, n = online.size();
        vector<vector<pair<int, int>>> to(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            to[u].push_back(make_pair(v, w));
            n = max(n, u);
            n = max(n, v);
        }
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(n, to, online, k, mid)) l = mid;
                else r = mid - 1;
        }
        return l == -1 ? -1 : l + 1;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;

    vector<vector<int>> edges = {
        // {0, 1, 7},
        // {1, 4, 5},
        // {0, 2, 6},
        // {2, 3, 6},
        // {3, 4, 2},
        // {2, 4, 6}
    };

    vector<bool> online = {true, true, true, false, true};
    long long k = 12;

    int result = sol.findMaxPathScore(edges, online, k);
    cout << "Max path score = " << result << endl;

    return 0;
}
#endif