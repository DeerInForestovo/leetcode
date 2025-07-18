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

/*
Link List Solution: 84ms Beats 56.37%, 177.13 MB Beats 55.95%
*/

// class LRUCache {
// public:
//     struct ListNode {
//         ListNode *next;
//         int val;
//         ListNode(int v) : next(nullptr), val(v) {}
//     };
//     vector<int> cache;
//     vector<int> health;
//     int capacity, cur_capacity;
//     ListNode *head, *cur;
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         cur_capacity = 0;
//         cache = vector<int>(10001, -1);
//         health = vector<int>(10001, 0);
//         head = new ListNode(-1);
//         cur = head;
//     }
    
//     int get(int key) {
//         if (cache[key] != -1) {
//             ++health[key];
//             cur -> next = new ListNode(key);
//             cur = cur -> next;
//         }
//         return cache[key];
//     }
    
//     void put(int key, int value) {
//         if (cache[key] != -1) {
//             cache[key] = value;
//             ++health[key];
//             cur->next = new ListNode(key);
//             cur = cur->next;
//         } else {
//             while (cur_capacity == capacity) {
//                 head = head->next; // old head -> dummy
//                 if (--health[head->val] == 0) {
//                     cache[head->val] = -1; // remove from cache
//                     --cur_capacity;
//                 }
//             }
//             ++cur_capacity;
//             cache[key] = value;
//             health[key] = 1;
//             cur->next = new ListNode(key);
//             cur = cur->next;
//         }
//     }
// };

class LRUCache {
public:
    int cache[10001], health[10001], history[400001], his_l = -1, his_r = -1, capacity, cur_capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cur_capacity = 0;
        memset(cache, -1, sizeof(cache));
        memset(health, 0, sizeof(health));
    }
    
    int get(int key) {
        if (cache[key] != -1) {
            ++health[key];
            history[++his_r] = key;
        }
        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache[key] != -1) {
            cache[key] = value;
            ++health[key];
            history[++his_r] = key;
        } else {
            while (cur_capacity == capacity) {
                if (--health[history[++his_l]] == 0) {
                    cache[history[his_l]] = -1;
                    --cur_capacity;
                }
            }
            ++cur_capacity;
            cache[key] = value;
            health[key] = 1;
            history[++his_r] = key;
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