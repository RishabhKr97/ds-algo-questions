/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
private:
    char to_lowercase(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch;
        }
        if (ch >= 'A' && ch <= 'Z') {
            int offset = ch - 'A';
            return 'a' + offset;
        }
        return ch;
    }

    bool is_alpha_numeric(char ch) {
        return (ch >= 'a' && ch <= 'z')
                || (ch >= 'A' && ch <= 'Z')
                || (ch >= '0' && ch <= '9');
    }
public:
    bool isPalindrome(string s) {
        int l = 0, h = s.size() - 1;
        while (l <= h) {
            if (!is_alpha_numeric(s[l])) {
                l++;
                continue;
            }
            if (!is_alpha_numeric(s[h])) {
                h--;
                continue;
            }

            char l_ch = to_lowercase(s[l]);
            char h_ch = to_lowercase(s[h]);
            if (l_ch != h_ch) {
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
};
// @lc code=end

