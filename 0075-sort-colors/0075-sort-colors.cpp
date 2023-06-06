class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables to keep the track of count of zero , ones , twos
        int zero=0,one=0,two=0;
        // Iterate over array nums
        for(auto i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }else if(nums[i]==1){
                one++;
            }else{
                two++;
            }
        }
        // Now update the nums array with varibales
        for(auto i=0;i<nums.size();i++){
            if(zero>0){
                nums[i]=0;
                zero--;
            }else if(one>0){
                nums[i]=1;
                one--;
            }else{
                nums[i]=2;
            }
        }
        return;
    }
};