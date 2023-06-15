class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0){
                    ans+=matrix[i][j];
                }else{
                    if(matrix[i][j] == 1){
                        matrix[i][j] = 1+min(matrix[i-1][j] , min(matrix[i][j-1] , matrix[i-1][j-1]));
                    }
                    ans+=matrix[i][j];
                }
            }
        }
        return ans;
    }
};