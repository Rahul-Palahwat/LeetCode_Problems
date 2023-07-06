class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0,ans = INT_MAX;
        int start = 0 , end = 0;
        while(end < nums.size()){
            while(sum >= target){
                ans = min(ans , end - start);
                sum-=nums[start];
                start++;
            }
            sum+=nums[end];
            end++;
        }
        while(sum>=target){
            ans = min(ans , end - start);
            sum-=nums[start];
            start++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};