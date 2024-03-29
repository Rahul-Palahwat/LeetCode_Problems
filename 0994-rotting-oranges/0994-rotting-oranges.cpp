class Solution {
public:
//     int n , m;
//     // using dfs for every rotten orange
//     queue<vector<int>> q;
//     int ans = 0;
//     void solve(vector<vector<int>>& grid , vector<vector<bool>>& vis){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j] == 2){
//                     q.push({i,j,0});
//                 }
//             }
//         }
//         while(!q.empty()){
//             int t = q.size();
//             while(t--){
//                 auto t = q.front();
//                 int i = t[0],j = t[1] , time = t[2];
//                 ans = max(ans , time);
//                 if(vis[i][j]){
//                     continue;
//                 }
//                 vis[t[0]][t[1]] = true;
//                 q.pop();
//                 if(i<n-1 && j<m){
//                     if(grid[i+1][j] == 1){
//                         q.push({i+1 , j , time+1});
//                         grid[i+1][j] = 2;
//                     }
//                 }
//                 if(i>0 && j<m){
//                     if(grid[i-1][j] == 1){
//                         q.push({i-1 , j , time+1});
//                         grid[i-1][j] = 2;
//                     }
//                 }
//                 if(i<n && j<m-1){
//                     if(grid[i][j+1] == 1){
//                         q.push({i , j+1 , time+1});
//                         grid[i][j+1] = 2;
//                     }
//                 }
//                 if(i<n && j>0){
//                     if(grid[i][j-1] == 1){
//                         q.push({i , j-1 , time+1});
//                         grid[i][j-1] = 2;
//                     }
//                 }
                
//             }
//         }
//         return;
//     }
    
//     int orangesRotting(vector<vector<int>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         vector<vector<bool>> vis(n , vector<bool>(m,false));
//         solve(grid , vis);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j] == 1){
//                     return -1;
//                 }
//             }
//         }
//         return ans;
//     }
    
    
    
    
    
    
    // New try
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis = grid;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            // cout<<sz<<" sz "<<endl;
            bool flag = false;
            while(sz--){
                auto top = q.front();
                q.pop();
                int i = top.first , j = top.second;
                // cout<<i<<" i "<<j<<endl;
                if(vis[i][j] == 0){
                    continue;
                }
                flag = true;
                // cout<<vis[i][j]<<"prev"<<endl;
                vis[i][j] = 0;
                // cout<<vis[i][j]<<"after"<<endl;
                if(i+1<n && vis[i+1][j] == 1){
                    q.push({i+1 , j});
                }
                if(j+1<m && vis[i][j+1] == 1){
                    q.push({i , j+1});
                }
                if(i-1>=0 && vis[i-1][j] == 1){
                    q.push({i-1 , j});
                }
                if(j-1>=0 && vis[i][j-1] == 1){
                    q.push({i , j-1});
                }
            }
            if(flag)
                ans++;
        }
        for(auto it: vis){
            for(auto i: it){
                if(i == 1){
                    return -1;
                }
            }
        }
        return ans-1 >0 ? ans-1 : 0;
    }
};