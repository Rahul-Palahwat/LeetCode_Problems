class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char , int> mp;
        for(auto it: s){
            mp[it]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second , it.first});
        }
        int sz = pq.top().first;
        if(sz*2 -1 > s.size()){
            return "";
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans+=top.second;
            if(pq.size() > 0){
                auto sec = pq.top();
                pq.pop();
                ans+=sec.second;
                if(sec.first > 1){
                    pq.push({sec.first-1 , sec.second});
                }
            }
            if(top.first > 1){
                pq.push({top.first-1 , top.second});
            }
        }
        return ans;
    }
};