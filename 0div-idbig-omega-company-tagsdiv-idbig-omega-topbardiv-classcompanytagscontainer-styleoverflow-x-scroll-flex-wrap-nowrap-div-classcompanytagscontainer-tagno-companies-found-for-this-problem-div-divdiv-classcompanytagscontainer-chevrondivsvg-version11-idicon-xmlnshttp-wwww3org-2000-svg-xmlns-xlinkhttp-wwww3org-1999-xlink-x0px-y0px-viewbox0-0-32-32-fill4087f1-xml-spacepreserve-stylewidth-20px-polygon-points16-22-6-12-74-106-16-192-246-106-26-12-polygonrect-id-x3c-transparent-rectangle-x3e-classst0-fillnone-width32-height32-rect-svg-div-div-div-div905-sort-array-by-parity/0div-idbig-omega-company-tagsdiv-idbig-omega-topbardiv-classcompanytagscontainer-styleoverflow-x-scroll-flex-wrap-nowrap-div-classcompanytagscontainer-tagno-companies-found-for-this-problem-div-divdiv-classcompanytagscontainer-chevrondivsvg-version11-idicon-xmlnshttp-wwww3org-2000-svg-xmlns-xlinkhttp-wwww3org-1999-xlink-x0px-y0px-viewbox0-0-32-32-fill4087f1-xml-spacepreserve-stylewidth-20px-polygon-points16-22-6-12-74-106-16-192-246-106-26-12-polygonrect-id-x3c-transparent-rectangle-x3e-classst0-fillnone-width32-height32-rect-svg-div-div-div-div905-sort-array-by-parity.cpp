class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        while(i<n && j<n){
            if(nums[i] %2 != 0){
                while(j<n && nums[j] % 2 != 0){
                    j++;
                }
                if(j<n)
                    swap(nums[i] , nums[j]);
                i++;
                j++;
            }else{
                i++;
                j=i;
            }
        }
        return nums;
    }
};