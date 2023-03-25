/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
private:
    bool findWord(const vector<vector<char>>& board, const string &word,
    vector<vector<bool>> &visited, int i, int j, int w) {
        if (w == word.size()) {
            return true;
        }

        if (i > 0 && visited[i-1][j] == false && board[i-1][j] == word[w]) {
            visited[i-1][j] = true;
            bool found = findWord(board, word, visited, i-1, j, w+1);
            visited[i-1][j] = false;
            if (found) {
                return true;
            }
        }
        if (i < board.size() - 1 && visited[i+1][j] == false && board[i+1][j] == word[w]) {
            visited[i+1][j] = true;
            bool found = findWord(board, word, visited, i+1, j, w+1);
            visited[i+1][j] = false;
            if (found) {
                return true;
            }
        }
        if (j > 0 && visited[i][j-1] == false && board[i][j-1] == word[w]) {
            visited[i][j-1] = true;
            bool found = findWord(board, word, visited, i, j-1, w+1);
            visited[i][j-1] = false;
            if (found) {
                return true;
            }
        }
        if (j < board[0].size() - 1 && visited[i][j+1] == false && board[i][j+1] == word[w]) {
            visited[i][j+1] = true;
            bool found = findWord(board, word, visited, i, j+1, w+1);
            visited[i][j+1] = false;
            if (found) {
                return true;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    bool found = findWord(board, word, visited, i, j, 1);
                    visited[i][j] = false;
                    if (found) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

