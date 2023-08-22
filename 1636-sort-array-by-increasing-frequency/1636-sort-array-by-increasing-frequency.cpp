class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        map<int, vector<int>> freq;
        vector<int> ans;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }
        for(auto it: freq){
            vector<int> temp = it.second;
            sort(temp.begin() , temp.end() , greater<int>());
            for(auto i: temp){
                int k = it.first;
                while(k--){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};