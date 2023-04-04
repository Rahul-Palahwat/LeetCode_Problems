class Solution {
public:
    int partitionString(string s) {
        int ans = 0 , n = s.length();
        unordered_map<char , int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = 1;
            }else{
                ans++;
                mp.clear();
                mp[s[i]] = 1;
            }
        }
        if(mp.size() > 0){
            ans++;
        }
        return ans;
    }
};