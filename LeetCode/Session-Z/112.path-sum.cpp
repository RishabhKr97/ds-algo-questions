/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool dfs_search(TreeNode *root, const int &targetSum, int currSum) {
        int new_sum = currSum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (new_sum == targetSum) {
                return true;
            }
            return false;
        }

        bool found = false;
        if (root->left) {
            found = dfs_search(root->left, targetSum, new_sum);
        }
        if (!found && root->right) {
            found = dfs_search(root->right, targetSum, new_sum);
        }
        return found;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return dfs_search(root, targetSum, 0);
    }
};
// @lc code=end

