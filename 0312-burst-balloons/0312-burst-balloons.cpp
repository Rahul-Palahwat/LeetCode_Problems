class Solution {
public:
    
    // Brute force recursion + memoization
    // int solve(vector<int>& nums , map<vector<int> , int> &mp){
    //     if(nums.size() == 1){
    //         return nums[0];
    //     }
    //     if(nums.size() == 2){
    //         return nums[1]*nums[0]+max(nums[1] , nums[0]);
    //     }
    //     if(mp[nums] != 0){
    //         return mp[nums];
    //     }
    //     int ans = INT_MIN;
    //     for(int i=0;i<nums.size();i++){
    //         if(i == 0){
    //             int val = nums[0];
    //             int temp = nums[0];
    //             if(i+1<nums.size()){
    //                 temp*=nums[i+1];
    //             }
    //             nums.erase(nums.begin()+0);
    //             temp+=solve(nums,mp);
    //             ans = max(ans , temp);
    //             nums.insert(nums.begin()+i , val);
    //         }else if(i == nums.size()-1){
    //             int val = nums[i];
    //             int temp = nums[i];
    //             if(i-1>=0){
    //                 temp*=nums[i-1];
    //             }
    //             nums.erase(nums.begin()+i);
    //             temp+=solve(nums , mp);
    //             ans = max(ans , temp);
    //             nums.insert(nums.begin()+i , val);
    //         }else{
    //             int val = nums[i];
    //             int temp = nums[i]*nums[i-1]*nums[i+1];
    //             nums.erase(nums.begin()+i);
    //             temp+=solve(nums, mp);
    //             ans = max(ans , temp);
    //             nums.insert(nums.begin()+i , val);
    //         }
    //     }
    //     return mp[nums] = ans;
    // }
    // int maxCoins(vector<int>& nums) {
    //     map<vector<int> , int> mp;
    //     return solve(nums , mp);
    // }
    
    
    
    
    
    // MCM Recursion + Memoization
    // int solve(vector<int>& nums , int i , int j, vector<vector<int>> &dp){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int ans = INT_MIN;
    //     for(int k=i;k<=j;k++){
    //         int temp = nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1,dp)+solve(nums , k+1 , j , dp);
    //         ans = max(ans , temp);
    //     }
    //     return dp[i][j] = ans;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.push_back(1);
    //     nums.insert(nums.begin()+0 , 1);
    //     int n = nums.size();
    //     vector<vector<int>> dp(n , vector<int>(n,-1));
    //     return solve(nums , 1 , nums.size()-2 , dp);
    // }
    
    
    
    
    // Tabulation
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin()+0 , 1);
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
        for(int i = sz;i > 0;i--){
            for(int j=i;j<=sz;j++){
                int ans = INT_MIN;
                for(int k=i;k<=j;k++){
                    int temp = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+dp[k+1][j];
                    ans = max(ans , temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][sz];
    }
};