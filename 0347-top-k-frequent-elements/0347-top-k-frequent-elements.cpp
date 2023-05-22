class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        map<int, vector<int> , greater<int>> maxi;
        for(auto it: mp){
            maxi[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(auto it: maxi){
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
                if(ans.size() == k){
                    return ans;
                }
            }
            // ans.push_back(it.second);
            
        }
        // cout<<endl;
        return ans;
    }
};