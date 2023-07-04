class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: nums){
            if(mp[it] == 1){
                ans = it;
                break;
            }
        }
        return ans;
    }
};