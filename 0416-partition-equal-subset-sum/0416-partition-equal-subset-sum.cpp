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
    bool solve(vector<int>& nums , int index , int sum, vector<vector<int>>& dp){
        if(index == nums.size()){
            if(sum == 0){
                return true;
            }
            return false;
        }
        if(sum < 0){
            return false;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        if(sum == 0){
            return true;
        }
        return dp[index][sum] = solve(nums , index+1 , sum ,dp) || solve(nums , index+1 , sum-nums[index] , dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum%2 != 0){
            return false;
        }
        sum/=2;
        vector<vector<int>> dp(nums.size()+1 , vector<int>(sum+1 , -1));
        return solve(nums , 0 , sum ,dp);
    }
};