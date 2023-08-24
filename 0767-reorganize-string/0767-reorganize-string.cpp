class Solution {
public:
    // string reorganizeString(string s) {
    //     string ans = "";
    //     unordered_map<char , int> mp;
    //     for(auto it: s){
    //         mp[it]++;
    //     }
    //     priority_queue<pair<int, char>> pq;
    //     for(auto it: mp){
    //         pq.push({it.second , it.first});
    //     }
    //     int sz = pq.top().first;
    //     if(sz*2 -1 > s.size()){
    //         return "";
    //     }
    //     while(!pq.empty()){
    //         auto top = pq.top();
    //         pq.pop();
    //         ans+=top.second;
    //         if(pq.size() > 0){
    //             auto sec = pq.top();
    //             pq.pop();
    //             ans+=sec.second;
    //             if(sec.first > 1){
    //                 pq.push({sec.first-1 , sec.second});
    //             }
    //         }
    //         if(top.first > 1){
    //             pq.push({top.first-1 , top.second});
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    
    
    // New approach O(26*N)
    string reorganizeString(string s) {
        unordered_map<char , int> mp;
        for(auto it: s){
            mp[it]++;
        }
        vector<pair<int, char>> v;
        for(auto it: mp){
            v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end() , greater<pair<int, char>>());
        if(v[0].first*2 -1 > s.size()){
            return "";
        }
        string temp = s;
        int cnt = 0 , i = 0 , j = 0;
        while(cnt < 2){
            while(i<s.size()){
                if(v[j].first == 0){
                    j++;
                }
                temp[i] = v[j].second;
                // cout<<v[j].first<<"second"<<endl;
                v[j].first -= 1;
                // cout<<v[j].first<<"after second"<<endl;
                i+=2;
            }
            i=1;
            cnt++;
        }
        return temp;
    }
};