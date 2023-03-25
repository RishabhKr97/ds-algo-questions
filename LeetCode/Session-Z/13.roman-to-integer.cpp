/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr_val = symbol_values[s[i]];
            if (i + 1 != s.size()) {
                int next_val = symbol_values[s[i+1]];
                if (curr_val < next_val) {
                    curr_val = next_val - curr_val;
                    i++;
                }
            }
            ans += curr_val;
        }

        return ans;
    }
};
// @lc code=end

