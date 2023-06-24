class Solution {
public:
    
    // Recursion + Memoization , Bruteforce Approach
    // int solve(int index , int len1 , int len2 , vector<int>& rods , vector<vector<vector<int>>> &dp){
    //     if(index == rods.size()){
    //         if(len1 == len2){
    //             return len1;
    //         }
    //         return 0;
    //     }
    //     if(dp[index][len1][len2] != -1){
    //         return dp[index][len1][len2];
    //     }
    //     // Not Taken
    //     int ans = solve(index+1 , len1 , len2 , rods , dp);
    //     // Taken in first
    //     ans = max(ans , solve(index+1 , len1+rods[index] , len2 , rods , dp));
    //     // Taken in second
    //     ans = max(ans , solve(index+1 , len1 , len2+rods[index] , rods , dp));
    //     return dp[index][len1][len2] = ans;
    // }
    // int tallestBillboard(vector<int>& rods) {
    //     int n = rods.size();
    //     int sum = 0;
    //     for(auto it: rods){
    //         sum+=it;
    //     }
    //     vector<vector<vector<int>>> dp(n , vector<vector<int>>(sum+1 , vector<int>(sum+1 , -1)));
    //     return solve(0 , 0 , 0 , rods , dp);
    // }
    
    
    
    // Optimized -> Recursion + Memoization
    int solve(int index , int diff , vector<int>& rods , vector<vector<int>> &dp){
        if(index == rods.size()){
            return diff == 0 ? 0 : -1e4;
        }
        if(dp[index][diff+5001] != -1){
            return dp[index][diff+5001];
        }
        int takenLeft = rods[index]+solve(index+1 , diff+rods[index] , rods , dp);
        int takenRight = solve(index+1 , diff-rods[index] , rods , dp);
        int skip = solve(index+1 , diff , rods , dp);
        return dp[index][diff+5001] = max({takenLeft , takenRight , skip});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n , vector<int>(2*5001 , -1));
        return solve(0 , 0 , rods , dp);
    }
};