class Solution {
public:
    bool cmp(map<char,int> mp , map<char , int> mp2){
        for(auto it: mp){
            if(mp2.find(it.first) != mp2.end()){
                if(it.second != mp2[it.first]){
                    return false;
                }
            }else{
                return false;
            }
            
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        map<char , int> mp;
        for(auto it: s1){
            mp[it]++;
        }
        map<char , int> mp2;
        for(int i=0;i<s1.length();i++){
            mp2[s2[i]]++;
        }
        int l = s1.length(),i=0;
        if(cmp(mp , mp2)){
            return true;
        }
        while(l<s2.length()){
            mp2[s2[l]]++;
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0){
                mp2.erase(s2[i]);
            }
            i++;
            l++;
            if(cmp(mp , mp2)){
                return true;
            }
        }
        return false;
    }
};