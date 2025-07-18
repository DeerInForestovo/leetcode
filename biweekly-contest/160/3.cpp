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
    int minTime(int n, vector<vector<int>> edges) {
        vector<pair<int, pair<int, int>>> adj[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            adj[u].push_back({v, {start, end}});
        }
        vector<int> minTime(n, INT_MAX);
        priority_queue<pair<int, int> > pq;
        minTime[0] = 0;
        pq.push({0, 0}); // {-time, node}
        while (!pq.empty()) {
            int time = -pq.top().first, node = pq.top().second;
            pq.pop();
            if (time > minTime[node]) continue;
            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first, start = neighbor.second.first, end = neighbor.second.second, ptime = time;
                if (ptime < start) ptime = start; // Wait until the start time
                if (ptime > end) continue; // Cannot reach this neighbor
                if (ptime + 1 < minTime[nextNode]) {
                    minTime[nextNode] = ptime + 1;
                    pq.push({-(ptime + 1), nextNode});
                }
            }
        }
        return minTime[n - 1] == INT_MAX ? -1 : minTime[n - 1];
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    // Input: n = 3, edges = [[0,1,0,1],[1,2,2,5]]©leetcode
    cout << sol.minTime(3, {{0, 1, 0, 1}, {1, 2, 2, 5}}) << endl; // Example usage
    // Input: n = 4, edges = [[0,1,0,3],[1,3,7,8],[0,2,1,5],[2,3,4,7]]©leetcode
    cout << sol.minTime(4, {{0, 1, 0, 3}, {1, 3, 7, 8}, {0, 2, 1, 5}, {2, 3, 4, 7}}) << endl; // Example usage
    // Input: n = 3, edges = [[1,0,1,3],[1,2,3,5]]©leetcode
    cout << sol.minTime(3, {{1, 0, 1, 3}, {1, 2, 3, 5}}) << endl; // Example usage
    // Input n = 4 edges = [[1,3,10,16],[0,2,6,7],[0,2,0,10],[0,3,3,15]]©leetcode
    cout << sol.minTime(4, {{1, 3, 10, 16}, {0, 2, 6, 7}, {0, 2, 0, 10}, {0, 3, 3, 15}}) << endl; // Example usage
    return 0;
}
#endif