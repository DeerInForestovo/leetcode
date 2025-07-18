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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (int i = 0; i + k <= n; i += k) {
            ListNode* tail = prev->next;
            ListNode* next = tail->next;
            for (int j = 1; j < k; ++j) {
                tail->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = tail->next;
            }
            prev = tail;
        }
        return dummy->next;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif