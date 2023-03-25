/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_count = 0, b_count = 0;
        ListNode *temp = headA;
        while(temp) {
            a_count++;
            temp = temp->next;
        }
        temp = headB;
        while(temp) {
            b_count++;
            temp = temp->next;
        }

        if (a_count < b_count) {
            int node_to_move = b_count - a_count;
            while(node_to_move--) {
                headB = headB->next;
            }
        } else if (b_count < a_count) {
            int node_to_move = a_count - b_count;
            while(node_to_move--) {
                headA = headA->next;
            }
        }

        while(headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
// @lc code=end

