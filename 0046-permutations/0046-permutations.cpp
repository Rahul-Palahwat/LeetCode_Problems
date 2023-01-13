class Solution {
public:
    void solve(vector<int> nums , int index , vector<vector<int>> & ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        solve(nums,index+1,ans);
        for(int i=index+1;i<nums.size();i++){
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            solve(nums,index+1,ans);
            
        }
        // int temp= nums[index];
        // nums[index] = nums[index-1];
        // nums[index-1] = temp;
        // solve(nums,index+1,ans);
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums , 0,ans);
        return ans;
    }
};