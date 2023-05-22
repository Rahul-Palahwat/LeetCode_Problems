class Solution {
public:
    // using map
    
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int , int> mp;
//         for(auto it: nums){
//             mp[it]++;
//         }
//         map<int, vector<int> , greater<int>> maxi;
//         for(auto it: mp){
//             maxi[it.second].push_back(it.first);
//         }
//         vector<int> ans;
//         for(auto it: maxi){
//             for(int i=0;i<it.second.size();i++){
//                 ans.push_back(it.second[i]);
//                 if(ans.size() == k){
//                     return ans;
//                 }
//             }
//             // ans.push_back(it.second);
            
//         }
//         // cout<<endl;
//         return ans;
//     }
    
    
    
    
    // Now using priority queue maxh
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> mp;
        vector<int> ans;
        for(auto it: nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second , it.first});
        }
        while(k--){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};