class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Vector for storing rows that will be zero
        vector<int> row(n , 0);
        // Vector for string column that will have zero
        vector<int> col(m , 0);
        // loop to update the row and col vector
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    // Increment the value from 0 to track the row
                    row[i]++;
                    // Increment the value at jth column from 0 to track the column
                    col[j]++;
                }
            }
        }
        // Now updation to the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // If we have encountered any row i or col j then we will update
                if(row[i] > 0 || col[j] > 0){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};