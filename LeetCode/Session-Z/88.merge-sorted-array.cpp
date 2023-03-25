/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
// with extra space
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int> merged(m + n);
    //     int nums1_index = 0, nums2_index = 0, merged_index = 0;

    //     while (nums1_index < m && nums2_index < n) {
    //         if (nums1[nums1_index] <= nums2[nums2_index]) {
    //             merged[merged_index++] = nums1[nums1_index++];
    //         } else {
    //             merged[merged_index++] = nums2[nums2_index++];
    //         }
    //     }

    //     while (nums1_index < m) {
    //         merged[merged_index++] = nums1[nums1_index++];
    //     }
    //     while (nums2_index < n) {
    //         merged[merged_index++] = nums2[nums2_index++];
    //     }

    //     for (int i = 0; i < merged_index; i++) {
    //         nums1[i] = merged[i];
    //     }
    // }
// without extra space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums_1_index = m - 1, nums_2_index = n - 1, write_index = m + n - 1;
        
        while (nums_1_index >= 0 && nums_2_index >= 0) {
            if (nums1[nums_1_index] >= nums2[nums_2_index]) {
                nums1[write_index--] = nums1[nums_1_index--];
            } else {
                nums1[write_index--] = nums2[nums_2_index--];
            }
        }

        while (nums_2_index >= 0) {
            nums1[write_index--] = nums2[nums_2_index--];
        }
    }
};
// @lc code=end

