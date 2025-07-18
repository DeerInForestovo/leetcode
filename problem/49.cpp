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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); ++i) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            if (anagrams.find(sortedStr) != anagrams.end()) {
                anagrams[sortedStr].push_back(strs[i]);
                continue;
            }
            vector<string> group;
            group.push_back(strs[i]);
            anagrams[sortedStr] = group;
        }
        for (const auto& pair : anagrams)
            result.push_back(pair.second);
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