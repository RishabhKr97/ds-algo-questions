/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_till_now = INT_MIN;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            largest_till_now = max(largest_till_now, curr_sum);
            curr_sum = max(curr_sum, 0);
        }
        return largest_till_now;
    }
};
// @lc code=end

