class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] != 0 && r > 0) {
                    matrix[r][c] += matrix[r - 1][c];
                }
            }
            
            vector<int> currRow = matrix[r];
            sort(currRow.begin(), currRow.end());
            for (int i = 0; i < n; i++) {
                ans = max(ans, currRow[i] * (n-i));
            }
        }
        
        return ans;
    }
};