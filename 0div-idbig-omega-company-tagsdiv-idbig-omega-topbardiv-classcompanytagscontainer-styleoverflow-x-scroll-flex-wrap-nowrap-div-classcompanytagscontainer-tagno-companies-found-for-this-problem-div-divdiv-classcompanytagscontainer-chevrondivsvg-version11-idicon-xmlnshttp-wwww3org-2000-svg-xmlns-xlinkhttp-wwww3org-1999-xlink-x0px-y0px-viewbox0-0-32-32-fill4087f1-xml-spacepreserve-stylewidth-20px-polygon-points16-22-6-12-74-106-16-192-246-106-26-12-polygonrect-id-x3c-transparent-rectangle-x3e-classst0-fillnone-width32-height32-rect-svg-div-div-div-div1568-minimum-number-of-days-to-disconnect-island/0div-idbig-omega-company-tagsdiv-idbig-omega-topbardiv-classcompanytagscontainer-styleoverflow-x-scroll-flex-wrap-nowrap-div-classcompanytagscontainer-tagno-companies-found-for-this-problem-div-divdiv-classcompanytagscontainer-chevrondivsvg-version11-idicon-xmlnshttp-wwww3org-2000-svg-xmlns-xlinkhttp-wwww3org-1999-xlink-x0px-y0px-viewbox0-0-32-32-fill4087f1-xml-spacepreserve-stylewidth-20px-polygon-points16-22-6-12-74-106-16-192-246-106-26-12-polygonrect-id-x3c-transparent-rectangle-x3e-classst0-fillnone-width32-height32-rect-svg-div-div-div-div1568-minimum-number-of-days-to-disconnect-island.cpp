class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        int n = grid.size() , m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(grid[i][j] == 0 || vis[i][j]){
            return;
        }
        vis[i][j] = true;
        dfs(i+1 , j , grid , vis);
        dfs(i-1 , j , grid , vis);
        dfs(i , j-1 , grid , vis);
        dfs(i , j+1 , grid , vis);
        return;
    }
    int solve(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                    dfs(i , j , grid , vis);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = solve(grid);
        if(cnt > 1 || cnt == 0){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int cnt = solve(grid);
                    if(cnt > 1 || cnt == 0){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};