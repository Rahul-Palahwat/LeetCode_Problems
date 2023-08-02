class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<bool> vis, vector<int> temp , vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(nums[i]);
                solve(vis , temp , nums);
                vis[i] = false;
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<bool> vis(n , false);
        solve(vis , temp, nums);
        return ans;
    }
};