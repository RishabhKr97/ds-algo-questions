/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string reversed_string = "";
        int index = s.size() - 1;
        bool first_word = true;
        while (index >= 0) {
            if (s[index] == ' ') {
                index--;
                continue;
            }
            int ending = index;
            while (index >= 0 && s[index] != ' ') {
                index--;
            }
            if (!first_word) {
                reversed_string += " ";
            }
            for (int i = index + 1; i <= ending; i++) {
                reversed_string += s[i];
            }
            first_word = false;
        }
        return reversed_string;
    }
};
// @lc code=end

