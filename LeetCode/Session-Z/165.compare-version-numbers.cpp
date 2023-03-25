/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (true) {
            int ver1 = 0, ver2 = 0;
            while (index1 < version1.size() && version1[index1] != '.') {
                ver1 *= 10;
                ver1 += (version1[index1] - '0');
                index1++;
            }
            index1++;

            while (index2 < version2.size() && version2[index2] != '.') {
                ver2 *= 10;
                ver2 += (version2[index2] - '0');
                index2++;
            }
            index2++;

            if (ver1 < ver2) {
                return -1;
            } else if (ver1 > ver2) {
                return 1;
            } else if (index1 >= version1.size() && index2 >= version2.size()) {
                return 0;
            }
        }
        return 0;
    }
};
// @lc code=end

