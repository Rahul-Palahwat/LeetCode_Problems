class Solution {
public:
    int ans = 1;
    void solve(int index , string &s, unordered_map<string, int> mp){
        int n = s.size();
        if(index >= n){
            int sz = mp.size();
            ans = max(ans , sz);
            return;
        }
        string temp="";
        for(int i=index;i<n;i++){
            temp+=s[i];
            if(mp.find(temp) == mp.end()){
                mp[temp]++;
                solve(i+1 , s , mp);
                // mp[temp]--;
                // if(mp[temp] == 0){
                    mp.erase(temp);
                // }
            }
            // temp.pop_back();
        }
        return;
    }
    int maxUniqueSplit(string s) {
        unordered_map<string , int> mp;
        string temp="";
        solve(0 , s , mp);
        return ans;
    }
};