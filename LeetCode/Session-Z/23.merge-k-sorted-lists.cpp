/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    int min_of_k(vector<ListNode*>& lists) {
        int curr_min = INT_MAX;
        int min_index = -1;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL && lists[i]->val < curr_min) {
                curr_min = lists[i]->val;
                min_index = i;
            }
        }

        return min_index;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *start;
        int curr_min_index = min_of_k(lists);
        if (curr_min_index == -1) return NULL;
        start = lists[curr_min_index];
        lists[curr_min_index] = lists[curr_min_index]->next;

        ListNode *curr = start;
        while(true) {
            curr_min_index = min_of_k(lists);
            if (curr_min_index == -1) break;

            curr->next = lists[curr_min_index];
            curr = curr->next;
            lists[curr_min_index] = lists[curr_min_index]->next;
        }

        return start;
    }
};
// @lc code=end

