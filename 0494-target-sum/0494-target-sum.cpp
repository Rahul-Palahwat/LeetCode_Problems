class Solution {
public:
    int solve(vector<int>& nums , int target , int index , vector<vector<int>>& dp){
        if(index < 0){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        int notTake = solve(nums , target , index-1 , dp),take = 0;
        if(nums[index]<= target){
            take = solve(nums , target-nums[index] , index-1 , dp);
        }
        return dp[index][target] = notTake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        if(abs(sum+target)%2 != 0 || abs(target) > sum){
            return 0;
        }
        target = (abs(sum-target))/2;
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
        return solve(nums , target , n-1 , dp);
    }
};