class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto it : mp){
            v.push_back({it.second , it.first});
        }
        sort(v.begin(),v.end());
        for(auto it: v){
            while(it.first--){
                ans+=it.second;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};