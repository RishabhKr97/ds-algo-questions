/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inOrder(TreeNode *curr, vector<int> &values) {
        if (curr == NULL) {
            return;
        }

        inOrder(curr->left, values);
        values.push_back(curr->val);
        inOrder(curr->right, values);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        inOrder(root, values);
        return values;
    }
};
// @lc code=end

