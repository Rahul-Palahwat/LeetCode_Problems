class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: t){
            if(mp.find(it) == mp.end()){
                return false;
            }
            if(mp[it] == 1){
                mp.erase(it);
            }else{
                mp[it]--;
            }
        }
        return mp.size() == 0;
    }
};