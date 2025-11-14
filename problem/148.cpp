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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return dummy.next;
    }
    ListNode* mergeSort(ListNode* head, int n) {
        if (n <= 1)
            return head;
        int mid = n / 2;
        ListNode* midNode = head;
        for (int i = 0; i < mid - 1; ++i)
            midNode = midNode->next;
        ListNode* rightHead = midNode->next;
        midNode->next = nullptr;
        ListNode* leftSorted = mergeSort(head, mid);
        ListNode* rightSorted = mergeSort(rightHead, n - mid);
        return merge(leftSorted, rightSorted);
    }
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (ListNode* node = head; node; node = node->next)
            ++n;
        return mergeSort(head, n);
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif