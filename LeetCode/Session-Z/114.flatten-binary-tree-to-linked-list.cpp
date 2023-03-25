/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        stack<TreeNode*> rightTrees;

        while (true) {
            if (root->right) {
                rightTrees.push(root->right);
            }

            root->right = root->left;
            root->left = NULL;

            if (root->right == NULL) {
                if (rightTrees.empty()) {
                    break;
                } else {
                    root->right = rightTrees.top();
                    rightTrees.pop();
                    root = root->right;
                }
            }
        }
    }
};
// @lc code=end

