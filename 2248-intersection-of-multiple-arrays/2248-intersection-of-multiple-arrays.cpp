class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums[0].size();i++){
            mp[nums[0][i]] = 1;
        }
        for(auto it: nums){
            map<int,int> temp;
            for(auto i: it){
                if(mp.find(i) != mp.end()){
                    temp[i] = 1;
                }
            }
            mp = temp;
        }
        for(auto it: mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};