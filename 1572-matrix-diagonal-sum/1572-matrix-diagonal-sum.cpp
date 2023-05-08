class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0;i<n;i++){
            ans+=mat[i][i];
        }
        for(int i=0,j=n-1;i<n;i++,j--){
            if(i != j){
                ans+=mat[i][j];
            }
        }
        return ans;
    }
};