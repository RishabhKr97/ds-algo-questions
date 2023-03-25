/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int target_sum = nums[i] * -1;
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int curr_sum = nums[start] + nums[end];
                if (curr_sum == target_sum) {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[start];
                    temp[2] = nums[end];
                    triplets.insert(temp);
                    start++;
                    end--;
                } else if (curr_sum < target_sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for (auto it = triplets.begin(); it != triplets.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};
// @lc code=end

