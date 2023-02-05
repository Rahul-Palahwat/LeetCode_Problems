class Solution {
public:
    bool check(map<char,int> mp1 , map<char,int> mp2){
        if(mp1.size() != mp2.size()){
            return false;
        }
        for(auto it: mp1){
            if(mp2.find(it.first) != mp2.end()){
                if(mp2[it.first] != it.second){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp1,mp2;
        vector<int> ans;
        if(p.length() > s.length()){
            return ans;
        }
        for(auto it: p){
            mp1[it]++;
        }
        int i=0,j;
        for(j=0;j<p.length();j++){
            mp2[s[j]]++;
        }
        if(check(mp1,mp2)){
            // cout<<"hello"<<endl;
            ans.push_back(i);
        }
        while(j<s.length()){
            mp2[s[j]]++;
            mp2[s[i]]--;
            if(mp2[s[i]] == 0){
                mp2.erase(s[i]);
            }
            j++;
            i++;
            if(check(mp1,mp2)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};