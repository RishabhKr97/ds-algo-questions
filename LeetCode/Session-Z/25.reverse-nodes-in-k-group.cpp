/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
private:
    ListNode* getNextKNode(ListNode *curr, int k) {
        while(--k && curr) {
            curr = curr->next;
        }
        return curr;
    }

    void reveseList(ListNode *begin, ListNode *end) {
        ListNode *curr = begin->next;
        while (begin != end) {
            ListNode *next = curr->next;
            curr->next = begin;
            begin = curr;
            curr = next;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *k_block_first, *k_block_last;
        ListNode *k_block_prev, *k_block_next;

        k_block_first = head;
        k_block_last = getNextKNode(k_block_first, k);
        if (k_block_last == NULL) {
            return head;
        }
        k_block_next = k_block_last->next;
        reveseList(k_block_first, k_block_last);
        head = k_block_last;
        k_block_first->next = k_block_next;

        k_block_prev = k_block_first;
        k_block_first = k_block_next;
        while (k_block_first) {
            k_block_last = getNextKNode(k_block_first, k);
            if (k_block_last == NULL) {
                break;
            }
            k_block_next = k_block_last->next;
            reveseList(k_block_first, k_block_last);
            k_block_prev->next = k_block_last;
            k_block_first->next = k_block_next;

            k_block_prev = k_block_first;
            k_block_first = k_block_next;
        }

        return head;
    }
};
// @lc code=end

