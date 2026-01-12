#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        workers.reserve(n);
        for (int i = 0; i < n; ++i) {
            workers.push_back({1.0 * wage[i] / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double result = 1e18, sum = 0;
        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;
            pq.push(q);
            sum += q;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = min(result, sum * ratio);
            }
        }
        return result;
    }
};