class Solution {
public:
    // int solve(int index , int prev , int diff , vector<int>& nums,vector<vector<vector<int>>> &dp){
    //     if(index == nums.size()){
    //         return 0;
    //     }
    //     if(dp[index][prev][diff] != -1){
    //         return dp[index][prev][diff];
    //     }
    //     if(prev == 0){
    //         return dp[index][prev][diff] = max(1+solve(index+1 , index+1 , diff , nums , dp) , solve(index+1, prev , diff , nums , dp));
    //     }else if(diff == 0){
    //         return dp[index][prev][diff] = max(1+solve(index+1 , index+1 , nums[index]-nums[prev-1]+500 , nums , dp) , solve(index+1 , prev , diff , nums , dp));
    //     }else{
    //         int possible=solve(index+1 , prev , diff , nums, dp);
    //         if(diff-500 == (nums[index] - nums[prev-1])){
    //             possible = max(possible , 1+solve(index+1 , index+1 , diff , nums , dp));
    //         }
    //         return dp[index][prev][diff] = possible;
    //     }
    // }
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(1000 , -1)));
    //     return solve(0 , 0 , 0 , nums,dp);
    // }
    int longestArithSeqLength(vector<int>& A) {
        int res = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                res = max(res, dp[j][d]);
            }
        return res;
    }
};