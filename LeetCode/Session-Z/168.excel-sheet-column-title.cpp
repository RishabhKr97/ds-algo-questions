/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber) {
            int temp = columnNumber % 26;
            if (temp == 0) {
                temp = 26;
            }
            ans += ('A' + temp - 1);
            columnNumber -= temp;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

