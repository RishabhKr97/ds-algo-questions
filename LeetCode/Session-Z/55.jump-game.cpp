/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance_left = 0;
        for (int i = 0; i < nums.size(); i++) {
            distance_left = max(distance_left - 1, nums[i]);
            if (distance_left <= 0 && i != nums.size() - 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

