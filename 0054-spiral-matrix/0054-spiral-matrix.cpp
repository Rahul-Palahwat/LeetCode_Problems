class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() , m = matrix[0].size() , i = 0 , j = 0 , cnt=0;
        while(i<n && j<m){
            if(cnt%2 == 0){
                for(int k = j;k<m;k++){
                    ans.push_back(matrix[i][k]);
                }
                i++;
                for(int k = i;k<n;k++){
                    ans.push_back(matrix[k][m-1]);
                }
                m--;
            }else{
                for(int k=m-1;k>=j;k--){
                    ans.push_back(matrix[n-1][k]);
                }
                n--;
                for(int k=n-1;k>=i;k--){
                    ans.push_back(matrix[k][j]);
                }
                j++;
            }
            cnt++;
        }
        return ans;
    }
};