/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[curr]) {
                curr++;
                nums[curr] = nums[i];
            }
        }
        return curr + 1;
    }
};
// @lc code=end

