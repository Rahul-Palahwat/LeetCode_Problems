// Recursion + Memoization
// class Solution {
// public:
//     // Recursive function to find ans
//     int solve(int index , vector<int>& nums , int prev, vector<vector<int>> &dp){
//         // Base Case
//         if(index == 0){
//             return prev != 0 ? nums[prev-1] > nums[index] : 1;
//         }
//         // Check for overlapping subproblem
//         if(dp[index][prev] != -1){
//             return dp[index][prev];
//         }
        
//         int ans = 0;
//         // when we haven't taken any element then prev == 0
//         if(prev == 0){
//             ans = max(1+solve(index-1 , nums , index+1 , dp) , solve(index-1 , nums , prev , dp));
//         }else if(nums[prev-1] > nums[index]){
//             ans = max(1+solve(index-1 , nums , index+1 , dp) , solve(index-1 , nums , prev , dp));
//         }else{
//             ans = solve(index-1 , nums , prev , dp);
//         }
//         // storing and returning the ans
//         return dp[index][prev] = ans;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // dp vector for memoization
//         vector<vector<int>> dp(n , vector<int>(n+1 , -1));
//         return solve(n-1 , nums , 0 , dp);
//     }
// };




// Tabulation 
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
//         for(int ind = n-1; ind>=0; ind --){
//             for (int prev_index = ind-1; prev_index >=-1; prev_index--){

//                 int notTake = 0 + dp[ind+1][prev_index +1];

//                 int take = 0;

//                 if(prev_index == -1 || nums[ind] > nums[prev_index]){

//                     take = 1 + dp[ind+1][ind+1];
//                 }

//                 dp[ind][prev_index+1] = max(notTake,take);

//             }
//         }
    
//         return dp[0][0];
//     }
// };



// Tabulation 1D DP
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // Initializing whole dp with all elements as 1 as we can have minimum LIS of 1 lenght in every case
//         vector<int> dp(n , 1);
//         int ans = 1;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 // checking the prev element if it's possible then take the max of now and prev
//                 if(nums[j] < nums[i]){
//                     dp[i] = max(dp[i] , 1+dp[j]);
//                     ans=max(ans , dp[i]);
//                 }
//             }
//         }
//         return ans;
//     }
// };



// Tabulation + Recursion
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp;
//         dp.push_back(nums[0]);
//         for(int i=1;i<nums.size();i++){
//             if(nums[i] > dp.back()){
//                 dp.push_back(nums[i]);
//             }else{
//                 int index = lower_bound(dp.begin() , dp.end() , nums[i]) - dp.begin();
//                 dp[index] = nums[i];
//             }
//         }
//         return dp.size();
//     }
// };






class Solution {
public:
    int solve(int index , vector<int>& nums, int prev , vector<vector<int>> &dp){
        if(index > nums.size()){
            return 0;
        }
        if(dp[index][prev] != -1){
            return dp[index][prev];
        }
        int notTaken = solve(index+1 , nums , prev , dp);
        int taken = 0;
        if(prev == 0){
            taken = 1+solve(index+1 , nums , index , dp);
        }else if(nums[index-1] > nums[prev-1]){
            taken = 1+solve(index+1 , nums , index , dp);
        }
        return dp[index][prev] = max(taken , notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return solve(1 , nums , 0 , dp);
    }
};