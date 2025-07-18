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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        for (int i = 1; i < left; ++i) {
            prev = cur;
            cur = cur->next;
        }
        ListNode* ori_left = cur;
        ListNode* ori_prev = prev;
        prev = cur;
        cur = cur->next;
        for (int i = left; i < right; ++i) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (ori_prev) ori_prev->next = prev;
        ori_left->next = cur;
        if (left == 1) return prev;
        return head;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif