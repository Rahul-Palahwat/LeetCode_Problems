class Solution {
public:
    // vector<pair<int,int>> paths = {{-1,1} , {-1 , 0} , {-1 , -1} , {0,-1},{0 , 1} , {1,0},{1,-1},{1,1}};
    // int solve(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& dp,vector<vector<bool>>& vis){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(i<0 || j<0 || i>=n || j>=m){
    //         return 1e7;
    //     }
    //     if(i == 0 && j == 0){
    //         return 1;
    //     }
    //     if(grid[i][j] == 1){
    //         return 1e7;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(vis[i][j]){
    //         return 1e7;
    //     }
    //     vis[i][j] = true;
    //     int ans = 1e7;
    //     for(auto it: paths){
    //         ans = min(ans , 1+solve(grid , i+it.first , j+it.second , dp ,vis));
    //     }
    //     return dp[i][j] = ans;
    // }
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     int n = grid.size() , m = grid[0].size();
    //     vector<vector<int>> dp(n , vector<int>(m,-1));
    //     vector<vector<bool>> vis(n , vector<bool>(m,false));
    //     int ans =  solve(grid , n-1 , m-1 , dp , vis);
    //     return ans >= 1e7 ? -1 : ans;
    // }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q;
  q.push({ 0, 0 });
  while (!q.empty()) {
    ++steps;
    queue<pair<int, int>> q1;
    while (!q.empty()) {
      auto c = q.front();
      q.pop();
      if (c.first >= 0 && c.second >= 0 && c.first < g.size() && c.second < g.size() && !g[c.first][c.second]) {
        g[c.first][c.second] = 1;
        if (c.first == g.size() - 1 && c.second == g.size() - 1) return steps;
        for (auto i = -1; i < 2; ++i)
          for (auto j = -1; j < 2; ++j)
            if (i != 0 || j != 0) q1.push({ c.first + i, c.second + j });
      }
    }
    swap(q, q1);
  }
  return -1;
}
};