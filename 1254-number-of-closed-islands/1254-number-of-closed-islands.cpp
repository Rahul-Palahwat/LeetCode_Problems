class Solution {
public:
    bool solve(int i , int j , vector<vector<int>>& grid , int n , int m){
        if(grid[i][j] == 1){
            return true;
        }
        grid[i][j] = 1;
        bool l = false , r = false , t = false , b = false;
        if(i-1 >= 0){
            t = solve(i-1 , j , grid , n , m);
        }
        if(i+1 < n){
            b = solve(i+1 , j , grid , n , m);
        }
        if(j-1 >= 0){
            l = solve(i , j-1 , grid , n , m);
        }
        if(j+1 < m){
            r = solve(i , j+1 , grid , n , m);
        }
        return l&&r&&t&&b;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    ans+=solve(i , j , grid , n , m);
                }
            }
        }
        return ans;
    }
};