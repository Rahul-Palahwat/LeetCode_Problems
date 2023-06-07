class Solution {
public:
    // int solve(int index , bool taken , vector<int>& nums){
    //     if(index < 0){
    //         if(taken){
    //             return 0;
    //         }
    //         return INT_MIN;
    //     }
    //     int ans = 0;
    //     if(taken){
    //         ans = max(nums[index]+solve(index-1 , taken , nums) , 0);
    //     }else{
    //         ans = max(nums[index]+solve(index-1 , true , nums) , solve(index-1 , taken , nums));
    //     }
    //     return ans;
    // }
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     return solve(n-1 , false , nums);
    // }
    
    
    
    int solve(int index , bool taken , vector<int>& nums , vector<vector<int>>& dp){
        if(index < 0){
            if(taken){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[index][taken] != -1){
            return dp[index][taken];
        }
        int ans = 0;
        if(taken){
            ans = max(nums[index]+solve(index-1 , taken , nums , dp) , 0);
        }else{
            ans = max(nums[index]+solve(index-1 , true , nums , dp) , solve(index-1 , taken , nums , dp));
        }
        return dp[index][taken] = ans;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));
        return solve(n-1 , false , nums , dp);
    }
};