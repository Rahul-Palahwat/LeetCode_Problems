class Solution {
public:
    // using property of xor
    // int singleNonDuplicate(vector<int>& nums) {
    //     int xo=0;
    //     for(auto it: nums){
    //         xo^=it;
    //     }
    //     return xo;
    // }
    
    // using binary search 
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = (start+end)/2;
            if((end-mid)%2 ==0){
                if(mid+1 < nums.size() && mid-1 >=0)
                if(nums[mid+1] == nums[mid]){
                    start = mid+2;
                }else if(nums[mid-1] == nums[mid]){
                    end = mid-2;
                }else{
                    return nums[mid];
                }
            }else{
                if(mid+1 < nums.size() && mid-1 >=0)
                if(nums[mid+1] == nums[mid]){
                    end = mid-1;
                }else if(nums[mid-1] == nums[mid]){
                    start = mid+1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[start];
    }
};