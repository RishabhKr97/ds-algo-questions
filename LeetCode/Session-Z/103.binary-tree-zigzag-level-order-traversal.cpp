/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if (root == NULL) {
            return traversal;
        }

        vector<TreeNode*> curr_level;
        curr_level.push_back(root);
        bool left_to_right = true;
        while(!curr_level.empty()) {
            vector<TreeNode*> temp;
            for (TreeNode *node : curr_level) {
                if (node->left) temp.push_back(node->left);
                if (node->right) temp.push_back(node->right);
            }

            vector<int> node_vals;
            if (left_to_right) {
                for (int i = 0; i < curr_level.size(); i++) {
                    node_vals.push_back(curr_level[i]->val);
                }
                left_to_right = false;
            } else {
                for (int i = curr_level.size() - 1; i >= 0; i--) {
                    node_vals.push_back(curr_level[i]->val);
                }
                left_to_right = true;
            }
            traversal.push_back(node_vals);
            curr_level = temp;
        }

        return traversal;
    }
};
// @lc code=end

