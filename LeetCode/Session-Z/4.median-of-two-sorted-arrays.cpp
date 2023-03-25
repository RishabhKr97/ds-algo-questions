/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 > N2) return findMedianSortedArrays(nums2, nums1);

        int l = 0, h = N1;
        int partition_size = (N1 + N2 + 1) / 2;
        while (l <= h) {
            int mid = (l + h) / 2;
            int partition = partition_size - mid;

            int nums1_left = mid <= 0 ? INT_MIN : nums1[mid-1];
            int nums1_right = mid >= N1 ? INT_MAX : nums1[mid];
            int nums2_left = partition <= 0 ? INT_MIN : nums2[partition-1];
            int nums2_right = partition >= N2 ? INT_MAX : nums2[partition];

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if ((N1 + N2) % 2 == 0) {
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right))/2.0;
                } else {
                    return max(nums1_left, nums2_left);
                }
            } else if (nums1_left > nums2_right) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;

    }
};
// @lc code=end

