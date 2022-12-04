class Solution {
public:
    void solve(vector<int> nums , int target , int index, vector<int> temp,vector<vector<int>>& ans){
        if(index == nums.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(nums[index] <= target){
            temp.push_back(nums[index]);
            solve(nums,target-nums[index],index,temp,ans);
            temp.pop_back();
        }
        solve(nums,target,index+1,temp,ans);
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates , target, 0, temp,ans);
        return ans;
    }
};