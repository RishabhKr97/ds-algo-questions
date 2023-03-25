/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (sieve[i] == true) {
                count++;
                int value = i * 2;
                while (value < n) {
                    sieve[value] = false;
                    value += i;
                }
            }
        }
        return count;
    }
};
// @lc code=end

