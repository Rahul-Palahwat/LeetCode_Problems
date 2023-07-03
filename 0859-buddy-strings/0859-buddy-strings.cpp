class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        map<char , int> mp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: goal){
            if(mp[it]>=1){
                mp[it]--;
                if(mp[it] == 0){
                    mp.erase(it);
                }
            }else{
                return false;
            }
        }
        int cnt = 0 , flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != goal[i]){
                cnt++;
            }
            mp[s[i]]++;
            if(mp[s[i]] >= 2){
                flag=1;
            }
        }
        return cnt == 2 || (cnt == 0 && flag == 1);
    }
};