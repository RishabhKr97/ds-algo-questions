/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
private:
    int calcWays(string s, int idx, vector<int> &memo) {
        if (idx == s.size()) {
            return 1;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        
        int curr_num = s[idx] - '0';
        if (curr_num == 0) {
            memo[idx] = 0;
            return 0;
        }
        if (curr_num >= 3 || idx + 1 == s.size()) {
            int temp = calcWays(s, idx + 1, memo);
            memo[idx] = temp;
            return temp;
        }
        int next_num = s[idx+1] - '0';
        if (curr_num == 1 || (next_num >= 0 && next_num <= 6)) {
            int temp = calcWays(s, idx + 1, memo) + calcWays(s, idx + 2, memo);
            memo[idx] = temp;
            return temp;
        }
        int temp = calcWays(s, idx + 1, memo);
        memo[idx] = temp;
        return temp;
    }
public:
// recursion
    // int numDecodings(string s) {
    //     vector<int> memo(s.size(), -1);
    //     return calcWays(s, 0, memo);
    // }
// dp
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int dp[s.size() + 1];
        int curr_num, prev_num;

        curr_num = s[0] - '0';
        dp[0] = 1;
        if (curr_num != 0) {
            dp[1] = 1;
        } else {
            dp[1] = 0;
        }

        for (int i = 1; i < s.size(); i++) {
            curr_num = s[i] - '0';
            if (curr_num != 0) {
                dp[i + 1] = dp[i];
            } else {
                dp[i + 1] = 0;
            }

            prev_num = s[i-1] - '0';
            if (prev_num == 1 || (prev_num == 2 && curr_num >= 0 && curr_num <= 6)) {
                dp[i + 1] += dp[i-1];
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

