class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>> maxh;
        for(auto it: mp){
            maxh.push({it.second , it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};