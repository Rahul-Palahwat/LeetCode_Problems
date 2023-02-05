class Solution {
public:
    // long long minCost(vector<int>& basket1, vector<int>& basket2) {
    //     long long ans = 0;
    //     map<int,int> mp1,mp2;
    //     for(auto it: basket1){
    //         mp1[it]++;
    //     }
    //     for(auto it: basket2){
    //         mp2[it]++;
    //     }
    //     map<int,vector<int>> cc;
    //     for(auto it: mp1){
    //         if(it.second %2 ==0){
    //             int pp=it.second;
    //             if(mp2.find(it.first) != mp2.end()){
    //                 if(it.second >= mp2[it.first]){
    //                     pp = it.second - mp2[it.first];
    //                     mp2[it.first] = 0;
    //                 }else{
    //                     pp = mp2[it.first] - it.second;
    //                     mp2[it.first] = 0;
    //                 }
    //             }
    //             cout<<pp<<"pp"<<it.first<<endl;
    //             if(pp != 0)
    //             cc[pp].push_back(it.first);
    //             // cc.push_back({pp , it.first});
    //         }else{
    //             it.second--;
    //             mp2[it.first]--;
    //             if(mp2.find(it.first) == mp2.end()){
    //                 cout<<"hello"<<endl;
    //                 return -1;
    //             }
    //             int pp=it.second;
    //             if(it.second >= mp2[it.first]){
    //                 pp = it.second - mp2[it.first];
    //                 mp2[it.first] = 0;
    //             }else{
    //                 pp = mp2[it.first] - it.second;
    //                 mp2[it.first] = 0;
    //             }
    //             cout<<pp<<"pp 2 "<<it.first<<endl;
    //             if(pp!=0)
    //             cc[pp].push_back(it.first);
    //             // cc.push_back({pp , it.first});
    //         }
    //     }
    //     for(auto it: mp2){
    //         if(it.second ==0){
    //             continue;
    //         }
    //         if(it.second %2 == 0){
    //             cout<<it.second<<"sec"<<it.first<<endl;
    //             cc[it.second].push_back(it.first);
    //             // cc.push_back({it.second , it.first});
    //         }else{
    //             cout<<"hello2"<<endl;
    //             return -1;
    //         }
    //     }
    //     for(auto it: cc){
    //         cout<<it.second.size()<<" "<<it.first<<endl;
    //         if(it.second.size() % 2 == 0){
    //             sort(it.second.begin() , it.second.end());
    //             for(int i=0;i<it.second.size()/2;i++){
    //                 ans+=(it.second[i]*(it.first/2));
    //             }
    //         }else{
    //             return -1;
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    
    long long minCost(vector<int>& b1, vector<int>& b2) {
    map<int, long long> m;
    for (auto c : b1)
        ++m[c];
    for (auto c : b2)
        --m[c];
    long long swaps = 0, res = 0;
    for (auto [c, cnt] : m) {
        if (cnt % 2){
            return -1;
        }
        swaps += max(0LL, cnt / 2);
    }
    for (auto [c, cnt] : m) {
        long long take = min(swaps, abs(cnt) / 2);
        res += take * min(c, begin(m)->first * 2);
        swaps -= take;
    }
    return res;
}
};