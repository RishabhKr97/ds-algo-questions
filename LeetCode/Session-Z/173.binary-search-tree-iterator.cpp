/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
private:
    TreeNode* currentNode;
    unordered_map<TreeNode*, TreeNode*> parents;

public:
    BSTIterator(TreeNode* root) {
        currentNode = NULL;
        TreeNode *temp = NULL;
        while (root) {
            parents[root] = temp;
            currentNode = root;
            temp = root;
            root = root->left;
        }
    }
    
    int next() {
        int value = currentNode->val;
        if (currentNode->right) {
            TreeNode *temp = currentNode;
            TreeNode *root = currentNode->right;
            while (root) {
                parents[root] = temp;
                currentNode = root;
                temp = root;
                root = root->left;
            }
        } else {
            while (true) {
                TreeNode *parent = parents[currentNode];
                parents.erase(currentNode);
                if (parent == NULL || parent->left == currentNode) {
                    currentNode = parent;
                    break;
                }
                currentNode = parent;
            }
        }
        return value;
    }
    
    bool hasNext() {
        return currentNode != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

