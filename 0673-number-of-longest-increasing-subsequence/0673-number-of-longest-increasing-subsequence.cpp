class Solution {
public:
    int solve(int index , vector<int>& nums , int prevIndex){
        if(index == nums.size()){
            return 0;
        }
        if(prevIndex == -1){
            return max(solve(index+1 , nums , prevIndex) , 1+solve(index+1 , nums , index));
        }else{
            int notTaken = solve(index+1 , nums , prevIndex);
            int taken = INT_MIN;
            if(nums[index] > nums[prevIndex]){
                taken = 1+solve(index+1 , nums , index);
            }
            return max(taken , notTaken);
        }
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1) , cnt(n , 1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                }else if(nums[i] > nums[j] && 1+dp[j] == dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans += cnt[i];
            }
        }
        return ans;
        // return solve(0 , nums, -1);
    }
};