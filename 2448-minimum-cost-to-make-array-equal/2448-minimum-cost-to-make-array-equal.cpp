class Solution {
public:
    long long solve(int mid , vector<int>& nums , vector<int>& cost){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            ans+=(abs(mid-nums[i])*1LL*cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int start = nums[0] , end = nums[0];
        for(auto it: nums){
            start = min(start , it);
            end = max(end , it);
        }
        long long ans;
        while(start <= end){
            int mid = (start+end)/2;
            long long midAns = solve(mid , nums , cost);
            long long midL = solve(mid-1 , nums , cost);
            long long midR = solve(mid+1 , nums , cost);
            if(midL <= midAns){
                ans = min(midL , midAns);
                end = mid-1;
            }else{
                ans = min(midR , midAns);
                start = mid+1;
            }
        }
        return ans;
    }
};