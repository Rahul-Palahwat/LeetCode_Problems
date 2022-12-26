class Solution {
public:
    bool solve(vector<int> nums , int index , int dis){
        if(index == nums.size()-1){
            return true;
        }
        if((dis == 0) && (nums[index] == 0)){
            return false;
        }
        return solve(nums , index+1 , max(nums[index]-1 , dis-1));
    }
    bool canJump(vector<int>& nums) {
        // return solve(nums,0,nums[0]);
        // bool dp[nums.size()+1]={false};
        // dp[0]=true;
        int dis = nums[0];
        for(int i=1;i<nums.size();i++){
            dis--;
            if(dis < 0){
                return false;
                // dp[i]=true;
            }
            dis = max(dis , nums[i]);
        }
        return true;
    }
};