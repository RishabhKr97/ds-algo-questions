/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t test_int = 1;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & test_int) {
                count++;
            }
            test_int <<= 1;
        }
        return count;
    }
};
// @lc code=end

