/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int low_left = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - low_left);
            low_left = min(low_left, prices[i]);
        }
        return max_profit;
    }
};
// @lc code=end

