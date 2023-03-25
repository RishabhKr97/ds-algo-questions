/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> order_queue;
        vector<vector<int>> level_order;
        if (root == NULL) {
            return level_order;
        }

        order_queue.push(root);
        order_queue.push(NULL);
        vector<int> curr_level;
        while(!order_queue.empty()) {
            TreeNode *curr_node = order_queue.front();
            order_queue.pop();

            if (curr_node == NULL) {
                level_order.push_back(curr_level);
                if (!order_queue.empty()) {
                    order_queue.push(NULL);
                    curr_level = vector<int>();
                }
                continue;
            }

            curr_level.push_back(curr_node->val);
            if (curr_node->left) {
                order_queue.push(curr_node->left);
            }
            if (curr_node->right) {
                order_queue.push(curr_node->right);
            }
        }

        return level_order;
    }
};
// @lc code=end

