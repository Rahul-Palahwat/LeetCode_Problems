class Solution {
public:
    map<string , int> mp;
    bool solve(int index , string &s , vector<int> &dp){
        if(index >= s.size()){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        bool ans = false;
        string temp = "";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(mp.find(temp) != mp.end()){
                 ans = ans || solve(i+1 , s , dp);
            }
        }
        return dp[index] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        for(auto it: wordDict){
            mp[it]=1;
        }
        vector<int> dp(s.size() , -1);
        return solve(0 , s , dp);
    }
};