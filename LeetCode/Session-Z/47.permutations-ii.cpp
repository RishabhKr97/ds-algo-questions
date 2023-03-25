/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    void getPermutations(const vector<int>& nums, vector<vector<int>> &permutations,
                        vector<int> &curr, unordered_set<int> &picked) {
        
        if (curr.size() == nums.size()) {
            permutations.push_back(curr);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (picked.find(i) == picked.end()) {
                picked.insert(i);
                curr.push_back(nums[i]);
                getPermutations(nums, permutations, curr, picked);
                curr.pop_back();
                picked.erase(i);

                while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                    i++;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        vector<int> curr;
        unordered_set<int> picked;
        getPermutations(nums, permutations, curr, picked);
        return permutations;
    }
};
// @lc code=end

