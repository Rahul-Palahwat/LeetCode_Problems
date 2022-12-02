class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.length();i++){
            mp2[word2[i]]++;
        }
        unordered_map<int,int> mpf;
        for(auto it: mp1){
            if(mp2.find(it.first) == mp2.end()){
                // cout<<"1"<<endl;
                return false;
            }
            mpf[it.second]++;
        }
        for(auto it: mp2){
            if(mpf.find(it.second) == mpf.end()){
                // cout<<"2"<<endl;
                return false;
            }else{
                if(mpf[it.second] > 0){
                    mpf[it.second]-=1;
                }else{
                    // cout<<"3"<<endl;
                    return false;
                }
            }
        }
        for(auto it: mpf){
            if(it.second != 0){
                // cout<<"4"<<it.second<<endl;
                return false;
            }
        }
        return true;
    }
};