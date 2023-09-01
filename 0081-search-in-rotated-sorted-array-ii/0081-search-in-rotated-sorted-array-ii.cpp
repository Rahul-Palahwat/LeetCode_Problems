class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (high+low)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[low]){
                int temp = low;
                while(temp <= mid){
                    if(nums[temp] != nums[low]){
                        break;
                    }
                    temp++;
                }
                low = temp;
            }else if(nums[mid] > nums[low]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};