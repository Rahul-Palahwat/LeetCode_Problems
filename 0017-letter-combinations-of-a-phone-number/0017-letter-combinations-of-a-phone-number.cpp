class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> mp;
    void assig(){
        mp[0]="";
    mp['1']="";
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    }
    int n;
    void solve(int i,string s,string digits){
        if(i==n){
            ans.push_back(s);
        }else{
            for(auto it:mp[digits[i]]){
                solve(i+1,s+it,digits);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return ans;
        }
        assig();
        n=digits.length();
        string s="";
        solve(0,s,digits);
        return ans;
    }
};