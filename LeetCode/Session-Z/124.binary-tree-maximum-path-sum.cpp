/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
private:
    int SMALLEST = -2000;

    int max_path_to_root(TreeNode *root, int &global_max) {
        if (root == NULL) {
            return SMALLEST;
        }

        int left_max = max_path_to_root(root->left, global_max);
        int right_max = max_path_to_root(root->right, global_max);

        int root_max = root->val;
        root_max = max(root_max, left_max + root->val);
        root_max = max(root_max, right_max + root->val);

        global_max = max(global_max, root_max);
        global_max = max(global_max, left_max + right_max + root->val);

        return root_max;
    }
public:
    int maxPathSum(TreeNode* root) {
        int global_max = SMALLEST;
        max_path_to_root(root, global_max);
        return global_max;
    }
};
// @lc code=end

