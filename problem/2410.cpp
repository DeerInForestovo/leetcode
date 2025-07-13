#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        auto np = players.begin();
        for (auto t: trainers)
            if (np != players.end() && (*np) <= t) {
                    ++ans;
                    ++np;
                }
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif