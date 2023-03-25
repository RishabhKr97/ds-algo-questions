/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        unordered_map<char,char> reverse_parentheses = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                
                char top_char = parentheses.top();
                if (reverse_parentheses[top_char] != c) {
                    return false;
                }
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};
// @lc code=end

