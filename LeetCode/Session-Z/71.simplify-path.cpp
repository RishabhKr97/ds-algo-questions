/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> canonical_path;
        stringstream ss(path);
        string word;

        while (!ss.eof()) {
            getline(ss, word, '/');
            if (word.size() == 0 || word == ".") {
                continue;
            }
            if (word == "..") {
                if (canonical_path.size() != 0) {
                    canonical_path.pop_back();
                }
            } else {
                canonical_path.push_back(word);
            }
        }

        string final_path = "";
        for (string word : canonical_path) {
            final_path += "/";
            final_path += word;
        }
        if (final_path.size() == 0) {
            final_path = "/";
        }

        return final_path;
    }
};
// @lc code=end

