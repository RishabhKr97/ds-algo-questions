/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
private:
    static bool intervalComparator(const vector<int> &i1, const vector<int> &i2) {
        return i1[0] < i2[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervalComparator);
        vector<vector<int>> merged_intervals;
        int i = 0;
        while (i < intervals.size()) {
            vector<int> curr_interval(2);
            curr_interval[0] = intervals[i][0];
            curr_interval[1] = intervals[i][1];

            i++;
            while (i < intervals.size()) {
                if (intervals[i][0] <= curr_interval[1]) {
                    curr_interval[1] = max(curr_interval[1], intervals[i][1]);
                    i++;
                } else {
                    break;
                }
            }
            merged_intervals.push_back(curr_interval);
        }
        return merged_intervals;
    }
};
// @lc code=end

