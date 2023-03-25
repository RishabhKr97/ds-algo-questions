/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();
        int total_row_iterations = matrix_size / 2;

        for (int i = 0; i < total_row_iterations; i++) {
            for (int j = i; j < matrix_size - i - 1; j++) {
                int curr_row = i, curr_col = j;
                int new_row = curr_col, new_col = matrix_size - curr_row - 1;
                int prev_val = matrix[new_row][new_col];
                matrix[new_row][new_col] = matrix[curr_row][curr_col];

                for (int k = 0; k < 3; k++) {
                    curr_row = new_row;
                    curr_col = new_col;
                    new_row = curr_col;
                    new_col =  matrix_size - curr_row - 1;
                    int temp =  matrix[new_row][new_col];
                    matrix[new_row][new_col] = prev_val;
                    prev_val = temp;
                }
            }
        }
    }
};
// @lc code=end

