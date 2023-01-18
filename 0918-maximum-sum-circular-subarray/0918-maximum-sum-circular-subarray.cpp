class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        int maxi = INT_MIN,sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi = max(maxi , nums[i]);
        }
        if(maxi <= 0){
            return maxi;
        }
        vector<int> maxidp(n,0);
        vector<int> minidp(n,0);
        maxidp[0] = nums[0];
        minidp[0] = nums[0];
        for(int i=1;i<n;i++){
            maxidp[i] = max(maxidp[i-1]+nums[i] , nums[i]);
            minidp[i] = min(minidp[i-1]+nums[i] , nums[i]);
            ans = max(ans , max(maxidp[i] , sum - minidp[i]));
        }
        
        return ans;
    }
};