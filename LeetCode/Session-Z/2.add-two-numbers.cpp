/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL;
        ListNode *curr = NULL;
        ListNode *temp = NULL;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL) {
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;

            if (ans == NULL) {
                ans = new ListNode(sum);
                curr = ans;
            } else {
                temp = new ListNode(sum);
                curr->next = temp;
                curr = temp;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) {
            sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;

            temp = new ListNode(sum);
            curr->next = temp;
            curr = temp;

            l1 = l1->next;
        }

        while (l2 != NULL) {
            sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;

            temp = new ListNode(sum);
            curr->next = temp;
            curr = temp;

            l2 = l2->next;
        }

        if (carry) {
            temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }

        return ans;
    }
};
// @lc code=end

