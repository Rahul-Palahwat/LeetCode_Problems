class Solution {
public:
    // Recursion + Memoization
    // int solve(vector<int> &cuts , int i , int j, vector<vector<int>> &dp){
    //     if(i > j){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int mini = INT_MAX;
    //     for(int k=i;k<=j;k++){
    //         int cost = cuts[j+1]-cuts[i-1]+solve(cuts , i , k-1 , dp)+solve(cuts , k+1 , j , dp);
    //         mini = min(mini , cost);
    //     }
    //     return dp[i][j] = mini;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     cuts.push_back(n);
    //     cuts.push_back(0);
    //     sort(cuts.begin() , cuts.end());
    //     int sz = cuts.size();
    //     vector<vector<int>> dp(sz , vector<int>(sz , -1));
    //     return solve(cuts , 1 , sz-2 , dp);
    // }
    
    
    
    // Tabulation
    // int minCost(int n, vector<int>& cuts) {
    //     int sz = cuts.size();
    //     cuts.push_back(n);
    //     cuts.push_back(0);
    //     sort(cuts.begin() , cuts.end());
    //     vector<vector<int>> dp(sz+2 , vector<int>(sz+2 , 0));
    //     for(int i=sz;i>0;i--){
    //         for(int j=i;j<=sz;j++){
    //             int mini = INT_MAX;
    //             for(int k=i;k<=j;k++){
    //                 int cost = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
    //                 mini = min(mini , cost);
    //             }
    //             dp[i][j] = mini;
    //         }
    //     }
    //     return dp[1][sz];
    // }
    
    
    
    
    
    
    // Recursion + Memoization
    int solve(int i , int j , vector<int>& cuts , vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i;k<=j;k++){
            int temp = cuts[j+1]-cuts[i-1] + solve(i , k-1 , cuts , dp) + solve(k+1 , j , cuts , dp);
            ans = min(ans , temp);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz , vector<int>(sz , -1));
        return solve(1 , sz-2, cuts , dp);
    }
};