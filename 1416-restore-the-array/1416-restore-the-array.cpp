class Solution {
public:
    
    // Recusrion + memoization is giving TLE
    // int MOD = 1e9+7;
    // int solve(string s , int index , int k,vector<int>& dp){
    //     int n = s.length();
    //     if(index == n){
    //         return 1;
    //     }
    //     if(s[index] == '0'){
    //         return 0;
    //     }
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }
    //     string temp = "";
    //     int ans = 0 , prev=0;
    //     for(int i=index;i<n;i++){
    //         temp+=s[i];
    //         if((prev <= (k/10)) && stoi(temp) <= k){
    //             ans =(ans+ solve(s , i+1 , k ,dp))%MOD;
    //             prev = stoi(temp);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return dp[index] = ans;
    // }
    // int numberOfArrays(string s, int k) {
    //     vector<int> dp(s.length() , -1);
    //     return solve(s , 0 , k , dp);
    // }
    
    
    
    // Now Tabulation 
    int MOD = 1e9+7;
    int solve(string s , int index , int k,vector<int>& dp){
        int n = s.length();
        if(index == n){
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        string temp = "";
        int ans = 0 , prev=0;
        for(int i=index;i<n;i++){
            temp+=s[i];
            if((prev <= (k/10)) && stoi(temp) <= k){
                ans =(ans+ solve(s , i+1 , k ,dp))%MOD;
                prev = stoi(temp);
            }
            else{
                break;
            }
        }
        return dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1; 
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            for (long sz = 1, n = 0; i + sz <= s.size(); ++sz) {
                n = n * 10 + s[i + sz - 1] - '0';
                if (n > k)
                    break;
                dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
            }
        }
    return dp[0];
    }
};