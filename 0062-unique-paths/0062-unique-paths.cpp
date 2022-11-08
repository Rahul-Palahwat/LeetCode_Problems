class Solution {
public:
    int memo[101][101];
    int solve(int i,int j,int m,int n){
        if(i==m && j==n){
            return 1;
        }
        if(i>m){
            return 0;
        }
        if(j>n){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int t1=solve(i+1,j,m,n);
        int t2=solve(i,j+1,m,n);
        return memo[i][j]=t1+t2;
    }
    int uniquePaths(int m, int n) {
        memset(memo,-1,sizeof(memo));
        int ans = solve(0,0,m-1,n-1);
        return ans;
    }
};