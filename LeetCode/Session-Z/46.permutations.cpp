/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    void getPermutation(const vector<int> &nums, vector<vector<int>> &permutations,
    vector<int> &curr, unordered_set<int> &picked) {

        if (curr.size() == nums.size()) {
            permutations.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (picked.find(i) == picked.end()) {
                curr.push_back(nums[i]);
                picked.insert(i);
                getPermutation(nums, permutations, curr, picked);
                picked.erase(i);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> curr;
        unordered_set<int> picked;
        getPermutation(nums, permutations, curr, picked);
        return permutations;
    }
};
// @lc code=end

