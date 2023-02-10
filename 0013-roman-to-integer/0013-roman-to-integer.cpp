class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<string , int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        int n = s.length();
        for(int i=0;i<n;i++){
            string temp = "";
            temp+=s[i];
            if(i+1<n){
                temp+=s[i+1];
            }
            if(mp.find(temp) != mp.end()){
                ans+=mp[temp];
                i++;
            }else{
                temp.pop_back();
                ans+=mp[temp];
            }
        }
        return ans;
    }
};