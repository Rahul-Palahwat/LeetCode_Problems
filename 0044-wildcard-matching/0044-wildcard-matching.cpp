class Solution {
public:
    bool solve(string &s1 , string &s2 , int i , int j , vector<vector<int>>& dp){
        int n = s1.size() , m = s2.size();
        if(i==n-1 && j==m-1){
            if(s2[j] == '*' || s1[i] == s2[j] || s2[j] == '?'){
                return true;
            }
            return false;
        }
        if(i>=n || j>=m){
            if(j<m){
                while(s2[j] == '*'){
                    j++;
                }
                if(j == m){
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
                ans |= solve(s1,s2,i+1,j+1 , dp);
            }else if(s2[j] == '*'){
                ans |= solve(s1,s2,i+1,j,dp);
                ans |= solve(s1,s2,i+1,j+1 , dp);
                ans |= solve(s1,s2,i,j+1 , dp);
            }
            else{
                return false;
            }
        }else{
            ans |= solve(s1,s2,i+1,j+1 , dp);
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
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(s, p , 0 , 0 , dp);
    }
};