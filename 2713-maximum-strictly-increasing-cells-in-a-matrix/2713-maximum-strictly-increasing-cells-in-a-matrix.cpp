class Solution {
public:
    // int solve(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int up = 0 , left = 0 , down = 0 , right = 0,tempi = i , tempj=j,tt;
    //     while(tempi-1 >= 0){
    //         if(grid[tempi-1][j] > grid[i][j]){
    //             up = max(up ,1+solve(tempi-1 , j , grid ,dp));
    //         }
    //         tempi--;
    //     }
    //     tempi = i;
    //     tempj = j;
    //     while(tempj-1 >= 0){
    //         if(grid[i][tempj-1] > grid[i][j]){
    //             left = max(left , 1+solve(i , tempj-1 , grid , dp));
    //         }
    //         tempj--;
    //     }
    //     tempi = i;
    //     tempj = j;
    //     while(tempi+1 < n){
    //         if(grid[tempi+1][j] > grid[i][j]){
    //             down = max(down , 1+solve(tempi+1 , j , grid , dp));
    //         }
    //         tempi++;
    //     }
    //     tempi = i;
    //     tempj = j;
    //     while(tempj+1 < m){
    //         if(grid[i][tempj+1] > grid[i][j]){
    //             right = max(right , 1+solve(i , tempj+1 , grid , dp));
    //         }
    //         tempj++;
    //     }
    //     return dp[i][j] = max(up , max(left, max(right,down)));
    // }
    // int maxIncreasingCells(vector<vector<int>>& mat) {
    //     int ans = INT_MIN;
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(dp[i][j] == -1)
    //             ans = max(ans ,1+ solve(i , j , mat , dp));
    //         }
    //     }
    //     return ans;
    // }
    
     int maxIncreasingCells(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        map<int, vector<int>> A;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                A[M[i][j]].push_back(i * n + j);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> res(n + m, 0);
        for (auto& [a, pos] : A) {
            for (int p : pos) {
                int i = p / n, j = p % n;
                dp[i][j] = max(res[i], res[m + j]) + 1;
            }
            for (int p : pos) {
                int i = p / n, j = p % n;
                res[m + j] = max(res[m + j], dp[i][j]);
                res[i] = max(res[i], dp[i][j]);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};