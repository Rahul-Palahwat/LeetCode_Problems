class Solution {
public:
    
    // code using recursion
    // vector<vector<int>> dp;
    // int solveWithout(vector<int>& nums , int ind , int flag){
    //     if(ind <= 0){
    //         return 0;
    //     }
    //     // if(ind == 0){
    //     //     if()
    //     // }
    //     if(dp[ind][flag] != -1){
    //         return dp[ind][flag];
    //     }
    //     int take = 0 , leave = 0;
    //     if(flag == 0){
    //         take = nums[ind]+solveWithout(nums , ind - 1 , 1);
    //     }
    //     leave = solveWithout(nums , ind-1 , 0);
    //     return dp[ind][flag] = max(take , leave);
    // }
    // int solveWith(vector<int>& nums , int ind , int flag){
    //     if(ind < 0){
    //         return 0;
    //     }
    //     // if(ind == 0){
    //     //     if()
    //     // }
    //     if(dp[ind][flag] != -1){
    //         return dp[ind][flag];
    //     }
    //     int take = 0 , leave = 0;
    //     if(flag == 0){
    //         take = nums[ind]+solveWith(nums , ind - 1 , 1);
    //     }
    //     leave = solveWith(nums , ind-1 , 0);
    //     return dp[ind][flag] = max(take , leave);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     dp.resize(n , vector<int>(2,-1));
    //     if(n == 1){
    //         return nums[0];
    //     }
    //     if(n == 2){
    //         return max(nums[0] , nums[1]);
    //     }
    //     if(n==3){
    //         return max(nums[0] , max(nums[1] , nums[2]));
    //     }
    //     int withoutzero = solveWithout(nums , n-1 , 0);
    //     dp.resize(0 , vector<int>(0,-1));
    //     dp.resize(n , vector<int>(2,-1));
    //     int withzero = solveWith(nums , n-2 , 0);
    //     return max(withoutzero,withzero);
    // }
    
    
    
    
    // Now tabulation 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int prevwith = nums[0] , lastwith = 0 , prevwithout = nums[1] , lastwithout = 0;
        for(int i=1;i<n-1;i++){
            int temp = max(nums[i]+lastwith , prevwith);
            lastwith = prevwith;
            prevwith = temp;
        }
        for(int i=2;i<n;i++){
            int temp = max(nums[i]+lastwithout , prevwithout);
            lastwithout = prevwithout;
            prevwithout = temp;
        }
        return max(prevwith,prevwithout);
    }
};