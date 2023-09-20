class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = *max_element(nums.begin() , nums.end());
        vector<int> sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        for(int i=1;i<n;i++){
            long long sum = 0;
            for(auto it: sq){
                if((it*i) > n){
                    break;
                }
                sum+=nums[it*i-1];
            }
            ans = max(ans , sum);
        }
        return ans;
    }
};