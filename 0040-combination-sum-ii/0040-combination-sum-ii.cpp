class Solution {
public:
    void solve(vector<int> nums,int target , int index, vector<int> temp , vector<vector<int>>& ans){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
        for(int i=index;i<nums.size();i++){
            if((i>index) && (nums[i] == nums[i-1])){
                continue;
            }
            if(nums[i] > target){
                break;
            }
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],i+1,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        // vector<vector<int>> fin;
        vector<int> temp;
        solve(candidates , target , 0,temp,ans);
        return ans;
        // for(auto it: ans){
        //     fin.push_back(it);
        // }
        // return fin;
    }
};