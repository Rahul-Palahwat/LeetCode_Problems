class Solution {
public:
    int n , m;
    void solve(int i , int j , vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        solve(i+1 , j , grid);
        solve(i-1 , j , grid);
        solve(i , j+1 , grid);
        solve(i , j-1 , grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(i ,j , grid);
                }
            }
        }
        return ans;    
    }
};