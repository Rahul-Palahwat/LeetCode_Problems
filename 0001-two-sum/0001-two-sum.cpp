class Solution {
public:
    // first approach O(N^2)
    // then this 
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }   
    
};