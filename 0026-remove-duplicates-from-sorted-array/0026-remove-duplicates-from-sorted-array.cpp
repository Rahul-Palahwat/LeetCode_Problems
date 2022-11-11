class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0],i=1;
        for(int j: nums){
            if(j>prev){
                nums[i++]=j;
                prev=j;
            }
        }
        return i;
    }
};