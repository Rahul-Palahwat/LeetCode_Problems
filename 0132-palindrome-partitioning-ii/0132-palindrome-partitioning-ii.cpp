class Solution {
public:
    
    // Bruteforce , Recursion + Memoization
    // bool check(string s , int i , int j){
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // int solve(int i,int j , string &s , vector<vector<int>> &dp){
    //     if(i == j){
    //         return 0;
    //     }
    //     if(check(s ,i , j)){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int ans = INT_MAX;
    //     for(int index = i;index<j;index++){
    //         int temp = 1+solve(i , index, s , dp)+solve(index+1 , j , s,dp);
    //         // cout<<index<<" "<<j<<" "<<temp<<endl;
    //         ans = min(ans , temp);
    //     }
    //     return dp[i][j] = ans;
    // }
    // int minCut(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n , vector<int>(n , -1));
    //     return solve(0 , n-1 , s , dp);
    // }
    
    
    
    
    
    
    
    
    // Recursion + Memoization
    // bool check(int i , int j , string s){
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // int solve(int i , string &s , vector<int> &dp){
    //     if(i == s.size()){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     int ans = INT_MAX;
    //     for(int index = i;index<s.size();index++){
    //         if(check(i , index , s)){
    //             int temp = 1+solve(index+1 , s, dp);
    //             ans = min(ans , temp);
    //         }
    //     }
    //     return dp[i] = ans;
    // }
    // int minCut(string s) {
    //     int n = s.size();
    //     vector<int> dp(n, -1);
    //     return solve(0 , s , dp)-1;
    // }
    
    
    
    
    // Tabulation
    bool check(int i , int j , string &s){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            int ans = INT_MAX;
            for(int index = i;index<s.size();index++){
                if(check(i , index , s)){
                    int temp = 1+dp[index+1];
                    ans = min(ans , temp);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};