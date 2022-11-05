class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int mini,maxi;
        for(int i=0;i<nums.size()-1;i++){
            mini = nums[i];
            maxi = nums[i];
            for(int j=i+1;j<nums.size();j++){
                maxi=max(maxi,nums[j]);
                mini = min(mini,nums[j]);
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};