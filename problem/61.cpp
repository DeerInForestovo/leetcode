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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        if (n == 0 || k % n == 0) return head;
        int cut = n - k % n;
        cur = head;
        for (int i = 1; i < cut; ++i)
            cur = cur->next;
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        cur = newHead;
        while (cur && cur->next)
            cur = cur->next;
        if (cur) cur->next = head;
        return newHead;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif