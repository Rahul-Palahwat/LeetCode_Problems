class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1);
        vector<int> ans;
        int index=0,maxi = 1;
        vector<int> track(n,0);
        for(int i=1;i<n;i++){
            track[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < 1+dp[j]){
                        track[i] = j;
                    }
                    dp[i] = max(dp[i] , 1+dp[j]);
                    if(maxi < dp[i]){
                        maxi = dp[i];
                        index = i;
                    }
                }
            }
        }
        while(index >= 0){
            ans.push_back(nums[index]);
            if(track[index] == index){
                break;
            }
            index = track[index];
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};