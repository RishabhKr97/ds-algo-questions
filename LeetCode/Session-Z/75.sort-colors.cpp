/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
// Two pass
    // void sortColors(vector<int>& nums) {
    //     int red_count = 0, white_count = 0, blue_count = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) {
    //             red_count++;
    //         } else if (nums[i] == 1) {
    //             white_count++;
    //         } else {
    //             blue_count++;
    //         }
    //     }

    //     int index = 0;
    //     while (red_count--) {
    //         nums[index++] = 0;
    //     }
    //     while (white_count--) {
    //         nums[index++] = 1;
    //     }
    //     while (blue_count--) {
    //         nums[index++] = 2;
    //     }
        
    // }
// One Pass
    void sortColors(vector<int>& nums) {
        int red_pointer = 0, blue_pointer = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && i > red_pointer) {
                int temp = nums[red_pointer];
                nums[red_pointer++] = 0;
                nums[i] = temp;
                i--;
            } else if (nums[i] == 2 && i < blue_pointer) {
                int temp = nums[blue_pointer];
                nums[blue_pointer--] = 2;
                nums[i] = temp;
                i--;
            }
        }
    }
};
// @lc code=end

