class Solution {
public: 
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0]=nums[0];
        int ans= nums[0];
        for(int i=1;i<nums.size();i++){
            if((dp[i-1] + nums[i]) > 0){
                dp[i] = max(nums[i],dp[i-1]+nums[i]);
            }else{
                dp[i]=nums[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};