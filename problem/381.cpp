#include <bits/stdc++.h>

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> idx_map;

    RandomizedCollection() {
    }
    
    bool insert(int val) {
        nums.push_back(val);
        idx_map[val].insert(nums.size() - 1);
        return idx_map[val].size() == 1;
    }
    
    bool remove(int val) {
        if (idx_map.find(val) == idx_map.end() || idx_map[val].empty())
            return false;
        
        int remove_idx = *idx_map[val].begin();
        idx_map[val].erase(remove_idx);
        
        int last_val = nums.back();

        nums[remove_idx] = last_val;
        idx_map[last_val].insert(remove_idx);
        
        idx_map[last_val].erase(nums.size() - 1);
        nums.pop_back();
        
        return true;
    }
    
    int getRandom() {
        int random_index = (rand() << 15 | rand()) % nums.size();
        return nums[random_index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif