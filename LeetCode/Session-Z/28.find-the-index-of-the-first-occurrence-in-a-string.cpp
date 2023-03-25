/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
// O(mn)
    // int strStr(string haystack, string needle) {
    //     for (int i = 0; i < haystack.size(); i++) {
    //         int j = 0, k = i;
    //         while (k < haystack.size() && j < needle.size() && haystack[k] == needle[j]) {
    //             j++;
    //             k++;
    //         }
    //         if (j == needle.size()) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
// O(m+n)
    int strStr(string haystack, string needle) {
        vector<int> kmp(needle.size());
        kmp[0] = 0;
        int i = 0, j = 1;
        while (j < needle.size()) {
            if (needle[i] == needle[j]) {
                kmp[j] = i + 1;
                i++;
                j++;
            } else if (i == 0) {
                kmp[j] = 0;
                j++;
            } else {
                i = kmp[i-1];
            }
        }
        for (int val : kmp) cout<<val<<endl;
        i = 0, j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j != 0) {
                j = kmp[j-1];
            } else {
                i++;
            }
        }

        if (j == needle.size()) {
            return i - j;
        }
        return -1;
    }
};

