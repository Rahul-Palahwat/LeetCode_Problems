class Solution {
public:
    // 1st method
    // void solve(vector<int> nums , vector<vector<int>> &ans , vector<int> temp){
    //     if(nums.size()==0){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         temp.push_back(nums[i]);
    //         vector<int> t = nums;
    //         t.erase(t.begin()+i);
    //         solve(t,ans,temp);
    //         temp.pop_back();
    //     }
    //     return;
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     solve(nums,ans,temp);
    //     return ans;
    // }
    
    // 2nd method 
    void solve(vector<int>& nums, vector<vector<int>> &ans,int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};