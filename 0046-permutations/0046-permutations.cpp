class Solution {
public:
    void solve(vector<int> nums , vector<vector<int>> &ans , vector<int> temp){
        if(nums.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
            vector<int> t = nums;
            t.erase(t.begin()+i);
            solve(t,ans,temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp);
        return ans;
    }
};