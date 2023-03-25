/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
private:
    int minOfRotatedArray(vector<int>& nums) {
        int s = 0, e = nums.size();
        while (s < e) {
            if (nums[s] <= nums[e-1]) {
                return s;
            }

            int mid = (s + e) / 2;
            if (nums[mid] < nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }

            if (nums[mid] >= nums[s]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return -1;
    }
public:
    int findMin(vector<int>& nums) {
        int n = minOfRotatedArray(nums);
        return nums[n];
    }
};
// @lc code=end

