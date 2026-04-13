#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> cache_iter_map;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache_iter_map.find(key) != cache_iter_map.end()) {
            auto iter = cache_iter_map[key];
            int value = iter->second;  // if value is Object, use std::move
            cache.erase(iter);
            cache.push_front({key, value});
            cache_iter_map[key] = cache.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_iter_map.find(key) != cache_iter_map.end()) {
            auto iter = cache_iter_map[key];
            cache.erase(iter);
            cache.push_front({key, value});
            cache_iter_map[key] = cache.begin();
        } else {
            if (cache.size() >= capacity) {
                int evict_key = cache.back().first;
                cache.pop_back();
                cache_iter_map.erase(evict_key);
            }
            cache.push_front({key, value});
            cache_iter_map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif