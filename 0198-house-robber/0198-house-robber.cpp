class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int dp[n+1];
        if(n==1){
            return nums[0];
        }else if(n== 2){
            return max(nums[0],nums[1]);
        }
        else{
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = max(dp[1],dp[0]+nums[2]);
            for(int i=3;i<n;i++){
                dp[i] = max((nums[i] + dp[i-2]) , nums[i]+dp[i-3]);
            }
        }
        return max(dp[n-2],dp[n-1]);
    }
};