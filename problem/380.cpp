#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> val_to_idx;
    mt19937 rng;

public:
    RandomizedSet() : rng(random_device{}()) {}

    bool insert(int val) {
        if (val_to_idx.count(val)) return false;

        data.push_back(val);
        val_to_idx[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!val_to_idx.count(val)) return false;

        int idx = val_to_idx[val];
        int last = data.back();

        data[idx] = last;
        val_to_idx[last] = idx;

        data.pop_back();
        val_to_idx.erase(val);

        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, data.size() - 1);
        return data[dist(rng)];
    }
};


#ifdef LEETCODE_LOCAL
#include <iostream>
int main() {
    // Add test cases here
    
    return 0;
}
#endif