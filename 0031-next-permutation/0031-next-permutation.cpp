class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        for(;i>0;i--){
            if(nums[i-1] < nums[i]){
                int index;
                int diff = nums[i] - nums[i-1];
                for(int j=i;j<n;j++){
                    if(nums[j]>nums[i-1] && (diff >= (nums[j] - nums[i-1]))){
                        diff = nums[j] - nums[i-1];
                        index = j;
                    }
                }
                int temp = nums[i-1];
                nums[i-1] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        sort(nums.begin()+i , nums.end());
        return;
    }
};