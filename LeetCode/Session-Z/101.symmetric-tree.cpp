/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool checkSymmetry(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL || left->val != right->val) {
            return false;
        }

        return checkSymmetry(left->left, right->right)
                && checkSymmetry(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }
};
// @lc code=end

