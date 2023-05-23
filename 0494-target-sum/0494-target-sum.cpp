class Solution {
public:
    int solve(vector<int>& nums , int target , int index , map<pair<int , int> , int>& dp){
        if(index < 0){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(dp.find({index , target}) != dp.end()){
            return dp[{index , target}];
        }
        return dp[{index , target}] = solve(nums , target-nums[index] , index-1 ,dp)+solve(nums , target + nums[index] , index-1 , dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int> , int> dp;
        return solve(nums , target , n-1 , dp);
    }
};