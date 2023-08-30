class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int last = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i+1] >= nums[i]){
                continue;
            }
            int oper = (nums[i] + nums[i+1] - 1)/nums[i+1];
            res += oper-1;
            nums[i] /= oper;
        }
        return res;
    }
};