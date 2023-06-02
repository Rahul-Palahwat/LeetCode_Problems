class Solution {
public:
    
    // Recursion + Memoization
    // bool solve(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
    //     if(i==0 && j==0){
    //         if(s2[j] == '*' || s1[i] == s2[j] || s2[j] == '?'){
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(i<0 || j<0){
    //         if(j>=0){
    //             // cout<<"Hello"<<endl;
    //             while(j>= 0 && s2[j] == '*'){
    //                 j--;
    //             }
    //             if(j < 0){
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     bool ans = false;
    //     if(s1[i] != s2[j]){
    //         if(s2[j] == '?'){
    //             ans |= solve(s1,s2,i-1,j-1 , dp);
    //         }else if(s2[j] == '*'){
    //             ans |= solve(s1,s2,i-1,j,dp);
    //             ans |= solve(s1,s2,i-1,j-1 , dp);
    //             ans |= solve(s1,s2,i,j-1 , dp);
    //         }
    //         else{
    //             return false;
    //         }
    //     }else{
    //         ans |= solve(s1,s2,i-1,j-1 , dp);
    //     }
    //     return dp[i][j] = ans;
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size() , m = p.size();
    //     if(s.size() == 0){
    //         for(int i=0;i<m;i++){
    //             if(p[i] != '*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     if(p.size() == 0){
    //         return s.size() == 0;
    //     }
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     return solve(s, p , n-1, m-1 , dp);
    // }
    
    
    
    // Tabulation 
    bool solve(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
        if(i==0 && j==0){
            if(s2[j] == '*' || s1[i] == s2[j] || s2[j] == '?'){
                return true;
            }
            return false;
        }
        if(i<0 || j<0){
            if(j>=0){
                // cout<<"Hello"<<endl;
                while(j>= 0 && s2[j] == '*'){
                    j--;
                }
                if(j < 0){
                    return true;
                }
            }
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool ans = false;
        if(s1[i] != s2[j]){
            if(s2[j] == '?'){
                ans |= solve(s1,s2,i-1,j-1 , dp);
            }else if(s2[j] == '*'){
                ans |= solve(s1,s2,i-1,j,dp);
                ans |= solve(s1,s2,i-1,j-1 , dp);
                ans |= solve(s1,s2,i,j-1 , dp);
            }
            else{
                return false;
            }
        }else{
            ans |= solve(s1,s2,i-1,j-1 , dp);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        if(s.size() == 0){
            for(int i=0;i<m;i++){
                if(p[i] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(p.size() == 0){
            return s.size() == 0;
        }
        vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));
        dp[0][0] = true;
        for(int i=1;i<m+1;i++){
            if(p[i-1] != '*'){
                dp[0][i] = false;
            }else{
                dp[0][i] = dp[0][i-1];
            }
            // cout<<i<<" "<<dp[0][i]<<" ";
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    if(p[j-1] == '?'){
                        dp[i][j] = dp[i-1][j-1];
                    }else if(p[j-1] == '*'){
                        dp[i][j] = (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]);
                    }
                }
            }
        }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};


// "aa"
// "a"
// "aa"
// "*"
// "cb"
// "?a"
// ""
// "******"
// "abcabczzzde"
// "*abc???de*"
// "adceb"
// "*a*b"



