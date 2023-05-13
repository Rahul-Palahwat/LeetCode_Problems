class Solution {
public:
//     int MOD = 1e9+7;
//     map<string,int> mp;
//     int solve(string s,int low , int high , string o , string z){
//         // cout<<s<<" ";
//         if(s.length() > high){
//             return 0;
//         }
//         if(mp[s] > 0){
//             return mp[s];
//         }
//         // cout<<s<<endl;
//         if(s.length() >= low  && s.length() <= high){
//            return mp[s] = (1+solve(s+o , low , high , o , z)+solve(s+z , low , high , o , z))%MOD;
//         }
        
//         return mp[s] = (solve(s+o , low , high , o , z)+solve(s+z , low , high , o , z))%MOD;
//     }
//     int countGoodStrings(int low, int high, int zero, int one) {
//         string s = "";
//         string o(one , '1');
//         string z(zero , '0');
//         return solve(s , low, high,o , z);
//     }
    long long M = 1e9+7;
    bool check(int a,int b){
        if(a>b){
            return true;
        }
        return false;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        if(high == 0){
            return 0;
        }
        string s="";
        if(low == 0){
           s="Rahul"; 
        }
        int flag=0;
        long long finalans=0;
        vector<long long> ans(1000000);
        ans[0]=1;
        for(int i = 0; i < 200000; i++){
            ans[i + zero] = ans[i + zero] % M;
            // cout<<s<<endl;
            ans[i + zero] =ans[i + zero]+ ans[i];
            ans[i + one] = ans[i + one]%M;
            ans[i + one] =ans[i + one]+ ans[i];
        }
        // cout<<s<<"check"<<endl;
        for(int i = low; i <= high; i++){
            finalans = (finalans + ans[i])%M;
        }
        return finalans;
    }
};