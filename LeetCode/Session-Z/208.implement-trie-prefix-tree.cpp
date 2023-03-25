/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct TrieNode {
    TrieNode *next[26];
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        end = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->next[index] == NULL) {
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->next[index] == NULL) {
                return false;
            }
            curr = curr->next[index];
        }
        return curr->end == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (curr->next[index] == NULL) {
                return false;
            }
            curr = curr->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

