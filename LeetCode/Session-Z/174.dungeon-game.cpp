/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m][n];

        dp[m-1][n-1] = 1; 

        for (int i = m-2; i >= 0; i--) {
            int req_energy = dp[i+1][n-1] - dungeon[i+1][n-1];
            if (req_energy > 0) {
                dp[i][n-1] = req_energy;
            } else {
                dp[i][n-1] = 1;
            }
        }

        for (int i = n-2; i >= 0; i--) {
            int req_energy = dp[m-1][i+1] - dungeon[m-1][i+1];
            if (req_energy > 0) {
                dp[m-1][i] = req_energy;
            } else {
                dp[m-1][i] = 1;
            }
        }

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                int req_energy = min(dp[i+1][j] - dungeon[i+1][j], dp[i][j+1] - dungeon[i][j+1]);
                if (req_energy > 0) {
                    dp[i][j] = req_energy;
                } else {
                    dp[i][j] = 1;
                }
            }
        }

        int req_energy = dp[0][0] - dungeon[0][0];
        return req_energy > 0 ? req_energy : 1;
    }
};
// @lc code=end

