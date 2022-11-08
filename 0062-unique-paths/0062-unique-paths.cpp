class Solution {
public:
    
    // my first approach dp with memoization
    // int memo[101][101];
    // int solve(int i,int j,int m,int n){
    //     if(i==m && j==n){
    //         return 1;
    //     }
    //     if(i>m){
    //         return 0;
    //     }
    //     if(j>n){
    //         return 0;
    //     }
    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
    //     int t1=solve(i+1,j,m,n);
    //     int t2=solve(i,j+1,m,n);
    //     return memo[i][j]=t1+t2;
    // }
    // int uniquePaths(int m, int n) {
    //     memset(memo,-1,sizeof(memo));
    //     int ans = solve(0,0,m-1,n-1);
    //     return ans;
    // }
    
    
    // dp with matrix
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        dp[0][0]=1;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};