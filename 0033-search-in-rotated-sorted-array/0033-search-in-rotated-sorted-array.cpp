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
            if(nums[mid] == k){
                return mid;
            }
            //check if left is sorted
            if(nums[mid] >= nums[l]){
                if(nums[mid] >= k && nums[l] <=k){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }else {
                if(k >= nums[mid] && k<=nums[h]){
                    l = mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};