class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l=0;
        int h=nums.size()-1;
        if(nums.size() == 2){
            if(k == nums[0]){
                return 0;
            }else if(k == nums[1]){
                return 1;
            }return -1;
        }
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] > nums[l]){
                if( k == nums[mid]){
                    return mid;
                }else if(k == nums[l]){
                    return l;
                }else if(k== nums[h]){
                    return h;
                }
                else if(k<nums[mid] && k>nums[l]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }else{
                if( k == nums[mid]){
                    return mid;
                }else if(k == nums[l]){
                    return l;
                }else if(k== nums[h]){
                    return h;
                }
                else if(k<nums[mid]){
                    h=mid-1;
                }else if(k>nums[l]){
                    h=mid-1;
                }else if(k>nums[mid] && k<nums[l]){
                    l=mid+1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;
    }
};