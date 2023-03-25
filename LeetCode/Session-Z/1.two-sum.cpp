/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
// O(n2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> soln(2);
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 soln[0] = i;
    //                 soln[1] = j;
    //             }
    //         }
    //     }
    //     return soln;
    // }
 // O(nlogn)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> soln(2);
    //     unordered_map<int, vector<int>> indexes;
    //     int n = nums.size();

    //     if (n < 2) return soln;

    //     for (int i = 0; i < n; i++) {
    //         if (indexes.find(nums[i]) == indexes.end()) {
    //             indexes[nums[i]] = vector<int> {i};
    //         } else {
    //             indexes[nums[i]].push_back(i);
    //         }
    //     }

    //     sort(nums.begin(), nums.end());
    //     int curr_sum;
    //     int i = 0, j = n - 1;
    //     while (i != j) {
    //         curr_sum = nums[i] + nums[j];
    //         if (curr_sum == target) {
    //             break;
    //         } else if (curr_sum < target) {
    //             i++;
    //         } else {
    //             j--;
    //         }
    //     }

    //     if (i == j) return soln;

    //     soln[0] = indexes[nums[i]][0];
    //     if (nums[i] == nums[j]) {
    //         soln[1] = indexes[nums[j]][1];
    //     } else {
    //         soln[1] = indexes[nums[j]][0];
    //     }
    //     return soln;
    // }
// O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        vector<int> soln(2);

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (index.find(complement) != index.end()) {
                soln[0] = index[complement];
                soln[1] = i;
                return soln;
            }
            index[nums[i]] = i;
        }
        return soln;
    }
};
// @lc code=end

