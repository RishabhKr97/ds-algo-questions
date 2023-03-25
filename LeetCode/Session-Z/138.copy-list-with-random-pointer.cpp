/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node *head_copy = new Node(head->val);

        map<Node*, Node*> copy;
        Node *curr = head;
        Node *curr_copy = head_copy;
        copy[head] = head_copy;
        while (curr) {
            if (curr->next) {
                Node *temp = new Node(curr->next->val);
                copy[curr->next] = temp;
                curr_copy->next = temp; 
            }
            curr = curr->next;
            curr_copy = curr_copy->next;
        }

        curr = head;
        curr_copy = head_copy;
        while (curr) {
            if (curr->random) {
                curr_copy->random = copy[curr->random];
            }
            curr = curr->next;
            curr_copy = curr_copy->next;
        }

        return head_copy;
    }
};
// @lc code=end

