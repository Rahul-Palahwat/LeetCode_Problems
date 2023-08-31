class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        if(n == 1){
            return nums[0] == target ? 0 : -1;
        }
        if(n==2){
            if(nums[0] == target){
                return 0;
            }else if(nums[1] == target){
                return 1;
            }
            return -1;
        }
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            // Left side is sorted
            if(nums[mid] >= nums[low]){
                if(target < nums[mid] && target >= nums[low]){
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
        return -1;
    }
};