/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
// O(1) space
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        if (k == 0) {
            return;
        }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

// O(n) space
    // void rotate(vector<int>& nums, int k) {
    //     int size = nums.size();
    //     if (k % size == 0) {
    //         return;
    //     }

    //     vector<int> temp(nums.size());
    //     for (int i = 0; i < nums.size(); i++) {
    //         int new_index = (i + k) % size;
    //         temp[new_index] = nums[i];
    //     }
    //     nums = temp;
    // }
};
// @lc code=end

