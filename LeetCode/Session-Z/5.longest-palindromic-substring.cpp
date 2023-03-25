/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private:
    int calcPalindrome(string &s, int left_index, int right_index) {
        while (left_index >= 0 && right_index < s.size()) {
            if (s[left_index] == s[right_index]) {
                left_index--;
                right_index++;
            } else {
                break;
            }
        }
        return right_index - left_index - 1;
    }
public:
    string longestPalindrome(string s) {
        int max_index = -1;
        int max_length = -1;
        for (int i = 0; i < s.size(); i++) {
            int curr_length = max(calcPalindrome(s, i-1, i+1), calcPalindrome(s, i, i+1));
            if (curr_length > max_length) {
                max_length = curr_length;
                max_index = i;
            }
        }

        if (max_length == -1) {
            return "";
        }
        
        string ans = "";
        int start = max_index - (max_length - 1)/2;
        while (ans.size() != max_length) {
            ans += s[start];
            start++;
        }
        return ans;
    }
};
// @lc code=end

