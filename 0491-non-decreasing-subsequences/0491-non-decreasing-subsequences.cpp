class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> nums , int index , vector<int> temp){
        if(index == nums.size()){
            if(temp.size() >1)
            ans.insert(temp);
            return;
        }
        solve(nums , index+1 , temp);
        if(temp.size() > 0){
            if(nums[index] >= temp[temp.size()-1]){
                temp.push_back(nums[index]);
                solve(nums , index+1,temp);
                temp.pop_back();
            }
        }else{
            temp.push_back(nums[index]);
            solve(nums , index+1 , temp);
        }
        return;
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        vector<vector<int>> finalans;
        for(auto it: ans){
            finalans.push_back(it);
        }
        return finalans;
    }
};