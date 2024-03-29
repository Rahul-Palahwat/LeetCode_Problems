class Solution {
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int n = obstacleGrid.size();
    //     int m = obstacleGrid[0].size();
    //     vector<vector<int>> dp(n , vector<int> (m , 0));
    //     bool flag = false;
    //     for(int i=0;i<n;i++){
    //         if(obstacleGrid[i][0] == 1){
    //             flag = true;
    //         }
    //         if(!flag){
    //             dp[i][0] = 1;
    //         }
    //     }
    //     flag = false;
    //     for(int i=0;i<m;i++){
    //         if(obstacleGrid[0][i] == 1){
    //             flag = true;
    //         }
    //         if(!flag){
    //             dp[0][i] = 1;
    //         }
    //     }
    //     for(int i=1;i<n;i++){
    //         for(int j=1;j<m;j++){
    //             if(obstacleGrid[i][j] == 1){
    //                 dp[i][j] = 0;
    //             }else{
    //                 dp[i][j] = dp[i-1][j]+dp[i][j-1];
    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    // }
    
    
    
    
    // Again solving
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n , vector<int> (m , 0));
        bool flag = true;
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0] == 1){
                flag = false;
            }
            if(flag)
                dp[i][0] = 1;
        }
        flag = true;
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i] == 1){
                flag = false;
            }
            if(flag)
                dp[0][i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};