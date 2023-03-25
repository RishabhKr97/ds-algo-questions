/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int matrix_rows = matrix.size();
        int matrix_cols = matrix[0].size();
        int total_spirals = (min(matrix_rows, matrix_cols) + 1) / 2;
        vector<int> spiral_order;

        for (int i = 0; i < total_spirals; i++) {
            for (int j = i; j < matrix_cols - i; j++) {
                spiral_order.push_back(matrix[i][j]);
            }

            if (matrix_cols - i - 1 > i) {
                for (int j = i + 1; j < matrix_rows - i; j++) {
                    spiral_order.push_back(matrix[j][matrix_cols - i - 1]);
                }
                
                if (matrix_rows - i - 1 > i) {
                    for (int j = matrix_cols - i - 2; j >= i; j--) {
                        spiral_order.push_back(matrix[matrix_rows - i - 1][j]);
                    }

                    for (int j = matrix_rows - i - 2; j > i; j--) {
                        spiral_order.push_back(matrix[j][i]);
                    }
                }
            }
        }

        if (matrix_cols % 2 == 1 && matrix_rows > matrix_cols) {
            for (int i = total_spirals; i < matrix_rows - total_spirals + 1; i++) {
                spiral_order.push_back(matrix[i][total_spirals - 1]);
            }
        }

        return spiral_order;
    }
};
// @lc code=end

