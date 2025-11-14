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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        
        priority_queue<int> max_heap;
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w)
                max_heap.push(projects[idx++].second);
            if (max_heap.empty()) break;
            w += max_heap.top();
            max_heap.pop();
        }
        return w;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif