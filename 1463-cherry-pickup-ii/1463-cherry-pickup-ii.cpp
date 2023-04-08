class Solution {
public:
    
    // Recursive solution bruteforce 
    // int ans = 0;
    // void solve(int fi , int fj , vector<vector<int>>& grid , int si , int sj,int ans1 , int ans2){
    //     int n = grid.size() , m = grid[0].size();
    //     if(fj<0 || fj >= m || sj < 0 || sj >=m){
    //         return;
    //     }
    //     if(fi == n || si == n){
    //         ans = max(ans , ans1+ans2);
    //         return;
    //     }
    //     if(fj == sj){
    //         ans1+=grid[si][sj];
    //     }else{
    //         ans1+=grid[fi][fj];
    //         ans2+=grid[si][sj];
    //     }
    //     solve(fi+1 , fj-1 , grid , si+1 , sj-1 , ans1,ans2);
    //     solve(fi+1 , fj-1 , grid , si+1 , sj , ans1,ans2);
    //     solve(fi+1 , fj-1 , grid , si+1 , sj+1 , ans1,ans2);
    //     solve(fi+1 , fj , grid , si+1 , sj-1 , ans1,ans2);
    //     solve(fi+1 , fj , grid , si+1 , sj , ans1,ans2);
    //     solve(fi+1 , fj , grid , si+1 , sj+1 , ans1,ans2);
    //     solve(fi+1 , fj+1 , grid , si+1 , sj-1 , ans1,ans2);
    //     solve(fi+1 , fj+1 , grid , si+1 , sj , ans1,ans2);
    //     solve(fi+1 , fj+1 , grid , si+1 , sj+1 , ans1,ans2);
    //     return;
    // }
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size() , m = grid[0].size(),ans1 = 0 , ans2 = 0;
    //     int dp[n][m][m];
    //     memset(dp , -1 , sizeof(dp));
    //     solve(0 , 0 , grid , 0 , m-1 , ans1 , ans2);
    //     return ans;
    // }
    
    
    // Memoization 
    vector<vector<vector<int>>> dp;
    int solve(int fi , int fj , vector<vector<int>>& grid , int si , int sj){
        int n = grid.size() , m = grid[0].size();
        if(fj<0 || fj >= m || sj < 0 || sj >=m || fi >= n){
            return 0;
        }
        if(dp[fi][fj][sj] != -1){
            return dp[fi][fj][sj];
        }
        int temp = 0;
        if(fj == sj){
            temp+=grid[si][sj];
        }else{
            temp+=grid[fi][fj];
            temp+=grid[si][sj];
        }
        int one = solve(fi+1 , fj-1 , grid , si+1 , sj-1);
        one =max(one , solve(fi+1 , fj-1 , grid , si+1 , sj));
        one =max(one , solve(fi+1 , fj-1 , grid , si+1 , sj+1 ));
        one =max(one , solve(fi+1 , fj , grid , si+1 , sj-1 ));
        one =max(one , solve(fi+1 , fj , grid , si+1 , sj ));
        one =max(one , solve(fi+1 , fj , grid , si+1 , sj+1 ));
        one =max(one , solve(fi+1 , fj+1 , grid , si+1 , sj-1 ));
        one =max(one , solve(fi+1 , fj+1 , grid , si+1 , sj ));
        one =max(one , solve(fi+1 , fj+1 , grid , si+1 , sj+1 ));
        return dp[fi][fj][sj] = one+temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        dp.resize(n+1 , vector<vector<int>>(m+1 , vector<int>(m+1 , -1)));
        return solve(0 , 0 , grid , 0 , m-1);
    }
};