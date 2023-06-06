class Solution {
public:
    int solve(int index , vector<int>& nums , int prev, vector<vector<int>> &dp){
        if(index == 0){
            return prev != 0 ? nums[prev-1] > nums[index] : 1;
        }
        if(dp[index][prev] != -1){
            return dp[index][prev];
        }
        int ans = 0;
        if(prev == 0){
            ans = max(1+solve(index-1 , nums , index+1 , dp) , solve(index-1 , nums , prev , dp));
        }else if(nums[prev-1] > nums[index]){
            ans = max(1+solve(index-1 , nums , index+1 , dp) , solve(index-1 , nums , prev , dp));
        }else{
            ans = solve(index-1 , nums , prev , dp);
        }
        return dp[index][prev] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return solve(n-1 , nums , 0 , dp);
    }
};