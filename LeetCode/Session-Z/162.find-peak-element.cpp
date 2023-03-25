/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size();
        while (l < h) {
            int mid = (l + h) / 2;
            if (mid == l) {
                return mid;
            }
            if (mid == h - 1) {
                if (nums[mid] > nums[mid-1]) {
                    return mid;
                } else {
                    return mid - 1;
                }
            }
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            if (nums[mid-1] > nums[mid]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

