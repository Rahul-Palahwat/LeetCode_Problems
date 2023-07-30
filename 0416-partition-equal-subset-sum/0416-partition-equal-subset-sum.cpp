class Solution {
public:
    
    // recursion 
    // bool solve(vector<int>& nums , int index , int sum){
    //     if(index == nums.size()){
    //         if(sum == 0){
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(sum < 0){
    //         return false;
    //     }
    //     if(sum == 0){
    //         return true;
    //     }
    //     return solve(nums , index+1 , sum) || solve(nums , index+1 , sum-nums[index]);
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto it: nums){
    //         sum+=it;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     sum/=2;
    //     return solve(nums , 0 , sum);
    // }
    
    
    // recursion + memoization 
    // bool solve(vector<int>& nums , int index , int sum, vector<vector<int>>& dp){
    //     if(index == nums.size()){
    //         if(sum == 0){
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(sum < 0){
    //         return false;
    //     }
    //     if(dp[index][sum] != -1){
    //         return dp[index][sum];
    //     }
    //     if(sum == 0){
    //         return true;
    //     }
    //     return dp[index][sum] = solve(nums , index+1 , sum ,dp) || solve(nums , index+1 , sum-nums[index] , dp);
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto it: nums){
    //         sum+=it;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     sum/=2;
    //     vector<vector<int>> dp(nums.size()+1 , vector<int>(sum+1 , -1));
    //     return solve(nums , 0 , sum ,dp);
    // }
    
    
    
    // Tabulation 
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0 , n = nums.size();
    //     for(auto it: nums){
    //         sum+=it;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     sum/=2;
    //     vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
    //     for(int i=0;i<n+1;i++){
    //         for(int j=0;j<sum+1;j++){
    //             if(i == 0 && j==0){
    //                 dp[i][j] = true;
    //             }else if(i == 0){
    //                 dp[i][j] = false;
    //             }else if(i == 0){
    //                 dp[i][j] = true;
    //             }
    //         }
    //     }
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<sum+1;j++){
    //             if(nums[i-1] <= j){
    //                 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
    //             }else{
    //                 dp[i][j] = dp[i-1][j];
    //             }
    //         }
    //     }
    //     return dp[n][sum];
    // }
    
    
    // Tabulation + Optimization
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0 , n = nums.size();
    //     for(auto it: nums){
    //         sum+=it;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     sum/=2;
    //     vector<bool> dp(sum+1 , false);
    //     dp[0] = true;
    //     for(int i=0;i<n;i++){
    //         vector<bool> temp(sum+1 , false);
    //         temp[0] = true;
    //         for(int j=1;j<sum+1;j++){
    //             if(nums[i] <= j){
    //                 temp[j] = dp[j] || dp[j-nums[i]];
    //             }else{
    //                 temp[j] = dp[j];
    //             }
    //         }
    //         dp = temp;
    //     }
    //     return dp[sum];
    // }
    
    
    
    
    
    // Recursion + Memoization
    bool solve(int index , int sum , vector<int>& nums , vector<vector<int>> &dp){
        if(index < 0){
            return sum == 0;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        bool notTaken = solve(index-1 , sum , nums , dp);
        bool taken = false;
        if(sum >= nums[index]){
            taken = solve(index-1 , sum-nums[index] , nums , dp);
        } 
        return dp[index][sum] = (taken || notTaken);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum%2 != 0){
            return false;
        }
        sum/=2;
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return solve(n-1 , sum , nums , dp);
    }
};