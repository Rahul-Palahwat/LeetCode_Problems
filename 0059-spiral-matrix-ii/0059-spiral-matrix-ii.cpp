class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int x=1,cnt = 0;
        int i=0,j=0,m=n;
        while(i<n || j<m){
            if(cnt%2 == 0){
                for(int k=j;k<m;k++){
                    ans[i][k] = x;
                    x++;
                }
                i++;
                for(int k=i;k<n;k++){
                    ans[k][m-1] = x;
                    x++;
                }
                m--;
            }else{
                for(int k=m-1;k>=j;k--){
                    ans[n-1][k] = x;
                    x++;
                }
                n--;
                for(int k=n-1;k>=i;k--){
                    ans[k][j] = x;
                    x++;
                }
                j++;
            }
            cnt++;
        }
        return ans;
    }
};