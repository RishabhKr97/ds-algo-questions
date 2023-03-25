/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildFromValues(vector<int>& inorder, unordered_map<int,int>& postorder_index,
    int s, int e) {
        int root_index = -1;
        int curr_index = INT_MIN;
        for (int i = s; i <= e; i++) {
            if (postorder_index[inorder[i]] > curr_index) {
                curr_index = postorder_index[inorder[i]];
                root_index = i;
            }
        }

        if (root_index == -1) {
            return NULL;
        }

        TreeNode *root = new TreeNode(inorder[root_index]);
        root->left = buildFromValues(inorder, postorder_index, s, root_index - 1);
        root->right = buildFromValues(inorder, postorder_index, root_index + 1, e);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> postorder_index;
        for (int i = 0; i < postorder.size(); i++) {
            postorder_index[postorder[i]] = i;
        }

        return buildFromValues(inorder, postorder_index, 0, inorder.size() -1);
    }
};
// @lc code=end

