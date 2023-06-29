class Solution {
public:
    // int solve(int cnt , int i , int j , vector<string>& grid, map<char,int> mp , vector<vector<int>> &dp , vector<vector<bool>> vis){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(cnt == 0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(vis[i][j]){
    //         return INT_MAX;
    //     }
    //     vis[i][j] = true;
    //     int ans = INT_MAX;
    //     if(i+1 < n){
    //         if(grid[i+1][j] == 'a' || grid[i+1][j] == 'b' || grid[i+1][j] == 'c' || grid[i+1][j] == 'd' || grid[i+1][j] == 'e' || grid[i+1][j] == 'f'){
    //             mp[grid[i+1][j]]=1;
    //             ans = min(ans , 1+solve(cnt-1 , i+1 , j , grid , mp , dp , vis));
    //             mp.erase(grid[i+1][j]);
    //         }else if(grid[i+1][j] == 'A' || grid[i+1][j] == 'B' || grid[i+1][j] == 'C' || grid[i+1][j] == 'D' || grid[i+1][j] == 'E' || grid[i+1][j] == 'F'){
    //             if(mp.find(grid[i+1][j]+32) != mp.end()){
    //                 ans = min(ans , 1+solve(cnt , i+1 , j , grid, mp , dp , vis));
    //             }
    //         }else if(grid[i+1][j] == '.'){
    //             ans = min(ans , 1+solve(cnt , i+1 , j , grid , mp , dp , vis));
    //         }
    //     }
    //     if(j+1 < m){
    //         if(grid[i][j+1] == 'a' || grid[i][j+1] == 'b' || grid[i][j+1] == 'c' || grid[i][j+1] == 'd' || grid[i][j+1] == 'e' || grid[i][j+1] == 'f'){
    //             mp[grid[i][j+1]]=1;
    //             ans = min(ans , 1+solve(cnt-1 , i , j+1 , grid , mp , dp , vis));
    //             mp.erase(grid[i][j+1]);
    //         }else if(grid[i][j+1] == 'A' || grid[i][j+1] == 'B' || grid[i][j+1] == 'C' || grid[i][j+1] == 'D' || grid[i][j+1] == 'E' || grid[i][j+1] == 'F'){
    //             if(mp.find(grid[i][j+1]+32) != mp.end()){
    //                 ans = min(ans , 1+solve(cnt , i , j+1 , grid, mp , dp , vis));
    //             }
    //         }else if(grid[i][j+1] == '.'){
    //             ans = min(ans , 1+solve(cnt , i , j+1 , grid , mp, dp , vis));
    //         }
    //     }
    //     if(i-1 >= 0){
    //         if(grid[i-1][j] == 'a' || grid[i-1][j] == 'b' || grid[i-1][j] == 'c' || grid[i-1][j] == 'd' || grid[i-1][j] == 'e' || grid[i-1][j] == 'f'){
    //             mp[grid[i-1][j]]=1;
    //             ans = min(ans , 1+solve(cnt-1 , i-1 , j , grid , mp , dp , vis));
    //             mp.erase(grid[i-1][j]);
    //         }else if(grid[i-1][j] == 'A' || grid[i-1][j] == 'B' || grid[i-1][j] == 'C' || grid[i-1][j] == 'D' || grid[i-1][j] == 'E' || grid[i-1][j] == 'F'){
    //             if(mp.find(grid[i-1][j]+32) != mp.end()){
    //                 ans = min(ans , 1+solve(cnt , i-1 , j , grid, mp , dp , vis));
    //             }
    //         }else if(grid[i-1][j] == '.'){
    //             ans = min(ans , 1+solve(cnt , i-1 , j , grid , mp , dp , vis));
    //         }
    //     }
    //     if(j-1 >= 0){
    //         if(grid[i][j-1] == 'a' || grid[i][j-1] == 'b' || grid[i][j-1] == 'c' || grid[i][j-1] == 'd' || grid[i][j-1] == 'e' || grid[i][j-1] == 'f'){
    //             mp[grid[i][j-1]]=1;
    //             ans = min(ans , 1+solve(cnt-1 , i , j-1 , grid , mp , dp , vis));
    //             mp.erase(grid[i][j-1]);
    //         }else if(grid[i][j-1] == 'A' || grid[i][j-1] == 'B' || grid[i][j-1] == 'C' || grid[i][j-1] == 'D' || grid[i][j-1] == 'E' || grid[i][j-1] == 'F'){
    //             if(mp.find(grid[i][j-1]+32) != mp.end()){
    //                 ans = min(ans , 1+solve(cnt , i , j-1 , grid, mp , dp , vis));
    //             }
    //         }else if(grid[i][j-1] == '.'){
    //             ans = min(ans , 1+solve(cnt , i , j-1 , grid , mp , dp , vis));
    //         }
    //     }
    //     return dp[i][j] = ans;
    // }
    // int shortestPathAllKeys(vector<string>& grid) {
    //     int n = grid.size() , m = grid[0].size();
    //     int cnt = 0 , starti ,startj;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j] == '@'){
    //                 starti = i;
    //                 startj = j;
    //             }
    //             if(grid[i][j] == 'a' || grid[i][j] == 'b' || grid[i][j] == 'c' || grid[i][j] == 'd' || grid[i][j] == 'e' || grid[i][j] == 'f'){
    //                 cnt++;
    //             }
    //         }
    //     }
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     vector<vector<bool>> vis(n , vector<int>(m , false));
    //     map<char , int> mp;
    //     return solve(cnt , starti , startj , grid, mp , dp , vis);
    // }
    int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n=m?grid[0].size():0;
    if(!m || !n) return 0;
    int path=0, K=0;
    vector<int> dirs={0,-1,0,1,0};
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i*n+j,0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='A' && grid[i][j]<='F') K++; //total alpha number
        }
    }
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int carry=q.front().second;
            q.pop();        
            if(carry==((1<<K)-1)) return path; //if all keys hold, just return 
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    k=carry|(1<<(grid[x][y]-'a')); //update hold keys
                }
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(carry & (1<<(grid[x][y]-'A')))) continue;
                }
                if(!visited[x][y][k]){
                    visited[x][y][k]=1;
                    q.push({x*n+y,k});
               }                
            }
        }
        path++;
    }
    return -1;
    }
};