/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void connect_level(Node *left, Node *right) {
        if (left == NULL || right == NULL) {
            return;
        }

        left->next = right;
        connect_level(left->left, left->right);
        connect_level(left->right, right->left);
        connect_level(right->left, right->right);
    }
public:
// extra space
    // Node* connect(Node* root) {
    //     if (root == NULL) {
    //         return root;
    //     }

    //     vector<Node*> curr_level;
    //     curr_level.push_back(root);

    //     while (!curr_level.empty()) {
    //         vector<Node*> temp_level;
    //         for (Node *node : curr_level) {
    //             if (node->left == NULL) {
    //                 break;
    //             }
    //             temp_level.push_back(node->left);
    //             temp_level.push_back(node->right);
    //         }

    //         for (int i = 0; i < curr_level.size() - 1; i++) {
    //             curr_level[i]->next = curr_level[i+1];
    //         }
    //         curr_level = temp_level;
    //     }

    //     return root;
    // }
// no extra space
    Node* connect(Node* root) {
        if (root != NULL) {
            connect_level(root->left, root->right);
        }
        return root;
    }
};
// @lc code=end

