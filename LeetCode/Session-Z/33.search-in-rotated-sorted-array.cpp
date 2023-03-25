/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
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

    int binarySearch(vector<int>& nums, int s, int e, int target) {
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = minOfRotatedArray(nums);
        int index = binarySearch(nums, 0, pivot, target);
        if (index == -1) {
            index = binarySearch(nums, pivot, nums.size(), target);
        }
        return index;
    }
};
// @lc code=end

