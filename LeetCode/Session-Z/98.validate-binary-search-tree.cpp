/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool validCheck(TreeNode *root, long upper_cap, long lower_cap) {
        if (root == NULL) {
            return true;
        }

        if (root->val < upper_cap && root->val > lower_cap) {
            return validCheck(root->left, root->val, lower_cap) &&
                    validCheck(root->right, upper_cap, root->val);
        }
 
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validCheck(root, LONG_MAX, LONG_MIN);
    }
};
// @lc code=end

