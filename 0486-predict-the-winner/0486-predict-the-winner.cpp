class Solution {
public:
    int solve(vector<int>&nums , int start , int end, vector<vector<int>>& dp){
        if(start> end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int left = nums[start] - solve(nums , start+1 , end ,dp);
        int right = nums[end]-solve(nums , start , end-1 , dp);
        return dp[start][end] = max(left , right);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        int score1 = solve(nums , 0 , n-1 , dp);
        return score1 >= 0;
    }
};