#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       vector<int> rows(m, 0); // Initialize with size m and values 0
        vector<int> columns(n, 0); // Initialize with size n and values 0


        // Mark rows and columns with zeroes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }

        // Set zeroes based on marked rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || columns[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};