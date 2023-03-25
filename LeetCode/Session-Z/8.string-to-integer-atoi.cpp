/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        long ans_limit = 2L << 31;
        bool is_positive = true;
        int curr_index = 0;
        int s_length = s.size();

        while (curr_index < s_length && s[curr_index] == ' ') curr_index++;

        if (curr_index < s_length && s[curr_index] == '-') {
            is_positive = false;
            curr_index++;
        } else if(curr_index < s_length && s[curr_index] == '+') {
            curr_index++;
        }

        while (curr_index < s_length && s[curr_index] >= '0' && s[curr_index] <= '9') {
            ans *= 10;
            ans += (s[curr_index] - '0');
            if (ans > ans_limit) {
                break;
            }
            curr_index++;
        }

        if (!is_positive) {
            ans *= -1;
        }

        if (ans < INT_MIN) return INT_MIN;
        else if (ans > INT_MAX) return INT_MAX;
        else return ans;
    }
};
// @lc code=end

