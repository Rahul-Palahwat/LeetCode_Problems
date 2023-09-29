class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        for(int i=1;i<n;i++){
            while(i<n && flag == 0 && nums[i] == nums[i-1]){
                i++;
            }
            if(i>=n){
                return true;
            }
            if(flag == 1 && nums[i] < nums[i-1]){
                return false;
            }
            if(flag == 2 && nums[i] > nums[i-1]){
                return false;
            }
            if(flag == 0 && nums[i] > nums[i-1]){
                flag = 1;
            }else if(flag == 0){
                flag = 2;
            }
        }
        return true;
    }
};