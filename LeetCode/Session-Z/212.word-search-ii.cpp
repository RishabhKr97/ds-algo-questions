/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
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
public:
    TrieNode *root;

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
    
    bool isEnding(TrieNode *curr) {
        return curr->end == true;
    }
    
    TrieNode* checkContinue(char next, TrieNode *curr) {
        return curr->next[next - 'a'];
    }
};

class Solution {
private:
    Trie trie;
    vector<string> found_words;
    unordered_set<string> all_words;
    vector<vector<bool>> visited;

    void dfs(const vector<vector<char>>& board, TrieNode *curr, int i, int j, string curr_word) {
        if (all_words.empty()) {
            return;
        }

        if (trie.isEnding(curr) && all_words.find(curr_word) != all_words.end()) {
            found_words.push_back(curr_word);
            all_words.erase(curr_word);
        }
        
        TrieNode *next;
        if (i != 0 && !visited[i-1][j]) {
            next = trie.checkContinue(board[i-1][j], curr);
            if (next) {
                visited[i-1][j] = true;
                dfs(board, next, i-1, j, curr_word+board[i-1][j]);
                visited[i-1][j] = false;
            }
        }
        if (i != board.size() - 1 && !visited[i+1][j]) {
            next = trie.checkContinue(board[i+1][j], curr);
            if (next) {
                visited[i+1][j] = true;
                dfs(board, next, i+1, j, curr_word+board[i+1][j]);
                visited[i+1][j] = false;
            }
        }
        if (j != 0 && !visited[i][j-1]) {
            next = trie.checkContinue(board[i][j-1], curr);
            if (next) {
                visited[i][j-1] = true;
                dfs(board, next, i, j-1, curr_word+board[i][j-1]);
                visited[i][j-1] = false;
            }
        } 
        if (j != board[i].size()-1 && !visited[i][j+1]) {
            next = trie.checkContinue(board[i][j+1], curr);
            if (next) {
                visited[i][j+1] = true;
                dfs(board, next, i, j+1, curr_word+board[i][j+1]);
                visited[i][j+1] = false;
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            trie.insert(word);
            all_words.insert(word);
        }
        visited = vector<vector<bool>>(board.size(), vector(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                TrieNode *next = trie.checkContinue(board[i][j], trie.root);
                if (next && found_words.size() != words.size()) {
                    visited[i][j] = true;
                    dfs(board, next, i, j, string(1, board[i][j]));
                    visited[i][j] = false;
                }
            }
        }
        return found_words;
    }
};
// @lc code=end

