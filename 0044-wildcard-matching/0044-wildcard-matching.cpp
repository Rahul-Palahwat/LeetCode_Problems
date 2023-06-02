class Solution {
public:
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
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(s, p , n-1, m-1 , dp);
    }
};



