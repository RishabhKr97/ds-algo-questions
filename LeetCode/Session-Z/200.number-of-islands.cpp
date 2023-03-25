/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        q.push(make_pair(i,j));
        while (!q.empty()) {
            pair<int,int> current = q.front();
            q.pop();
            int current_i = current.first;
            int current_j = current.second;
            if (current_i != 0 && !visited[current_i-1][current_j] && grid[current_i-1][current_j] == '1') {
                visited[current_i-1][current_j] = true;
                q.push(make_pair(current_i-1, current_j));
            }
            if (current_i != m - 1 && !visited[current_i+1][current_j] && grid[current_i+1][current_j] == '1') {
                visited[current_i+1][current_j] = true;
                q.push(make_pair(current_i+1, current_j));
            }
            if (current_j != 0 && !visited[current_i][current_j-1] && grid[current_i][current_j-1] == '1') {
                visited[current_i][current_j-1] = true;
                q.push(make_pair(current_i, current_j-1));
            }
            if (current_j != n - 1 && !visited[current_i][current_j+1] && grid[current_i][current_j+1] == '1') {
                visited[current_i][current_j+1] = true;
                q.push(make_pair(current_i, current_j+1));
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
// @lc code=end

