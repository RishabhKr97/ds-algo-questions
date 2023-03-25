/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i = columnTitle.size() - 1;
        int val = 0;
        long pow26 = 1;
        while (i >= 0) {
            val += ((columnTitle[i] - 'A' + 1) * pow26);
            pow26 *= 26;
            i--;
        }
        return val;
    }
};
// @lc code=end

