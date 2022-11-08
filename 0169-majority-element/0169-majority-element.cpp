class Solution {
public:
    int majorityElement(vector<int>& nums) {
        long long int count=1,max=0,element;
        sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                count++;
                if(count>max){
                    max=count;
                    element=nums[i];
                }
            }else{
                count=2;
            }
            
        }
        return element;
    }
        
};