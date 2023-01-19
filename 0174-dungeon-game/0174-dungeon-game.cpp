class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;
        
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];                
                // store this value
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
    
    
    
    
    // int ans = INT_MIN;
    // bool solve(int i,int j,int n,int m , vector<vector<int>> dun, int sum , int mini, vector<vector<bool>>& vis, vector<vector<bool>>& bo){
    //     if(i>= n || j>=m){
    //         return false;
    //     }
    //     if(i == n-1 && j== m-1){
    //         sum+=dun[i][j];
    //         mini = min(mini , sum);
    //         ans = max(ans , mini);
    //         return true;
    //     }
    //     if(vis[i][j] == true){
    //         return true;
    //     }
    //     vis[i][j] = true;
    //     sum+=dun[i][j];
    //     bool ret = false;
    //     if(solve(i+1,j,n,m,dun,sum,min(mini , sum),vis,bo)){
    //         bo[i+1][j] = true;
    //         ret|=true;
    //     }
    //     if(solve(i,j+1,n,m,dun,sum,min(mini , sum),vis,bo)){
    //         bo[i][j+1] = true;
    //         ret|=true;
    //     }
    //     return ret;
    // }
    // int calculateMinimumHP(vector<vector<int>>& dun) {
    //     int n=dun.size();
    //     int m = dun[0].size();
    //     vector<vector<bool>> vis(n , vector<bool>(m,0));
    //     vector<vector<bool>> bo(n , vector<bool>(m,0));
    //     bool t = solve(0,0,n,m,dun,0,0,vis,bo);
    //     return abs(ans)+1;
    // }
};