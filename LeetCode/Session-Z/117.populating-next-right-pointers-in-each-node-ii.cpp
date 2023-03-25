/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
public:
    Node* connect(Node* root) {
        Node *curr = root;
        while (curr) {
            Node *next_begin = NULL;
            Node *prev = NULL;
            while (curr) {
                if (curr->left) {
                    if (next_begin == NULL) {
                        next_begin = curr->left;
                    }
                    if (prev) {
                        prev->next = curr->left;
                    }
                    prev = curr->left;
                }
                if (curr->right) {
                    if (next_begin == NULL) {
                        next_begin = curr->right;
                    }
                    if (prev) {
                        prev->next = curr->right;
                    }
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = next_begin;
        }
        return root;
    }
};
// @lc code=end

