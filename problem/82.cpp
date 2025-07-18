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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0, head); // Dummy node to handle edge cases
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool hasDuplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                hasDuplicate = true;
                curr = curr->next;
            }
            if (hasDuplicate) {
                prev->next = curr->next; // Skip all duplicates
            } else {
                prev = prev->next; // Move prev only if no duplicates
            }
            curr = curr->next; // Move to the next node
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