class Solution {
public:
    long long solve(int index , vector<int>& nums , int x , vector<vector<long long>>& dp, int parity){
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][parity] != -1){
            return dp[index][parity];
        }
        long long ans = 0;
        long long notTaken = solve(index+1 , nums , x , dp, parity);
        long long take = 0;
        if(nums[index]%2 == parity){
            take = nums[index]+solve(index+1 , nums , x, dp , parity);
        }else{
            take = nums[index]-x+solve(index+1 , nums , x , dp , nums[index]%2);
        }
        return dp[index][parity] = max(take , notTaken);
    }
    long long maxScore(vector<int>& nums, int x) {
        long long sum = nums[0];
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2 , -1));
        return sum+=solve(1 , nums , x , dp , nums[0]%2);
    }
};