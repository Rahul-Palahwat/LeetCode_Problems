class Solution {
public:
    // int solve(int i , int j ,vector<vector<int>>& grid ,int n ,int m){
    //     queue<pair<int,int>> q;
    //     q.push({i , j});
    //     int ans = 0,flag=0;
    //     while(!q.empty()){
    //         auto top = q.front();
    //         q.pop();
    //         if((top.first <= 0) || (top.second <= 0)){
    //             flag=1;
    //             // return 0;
    //         }
    //         if((top.first >= (n-1)) || (top.second >= (m-1))){
    //             flag=1;
    //             // return 0;
    //         }
    //         if(grid[top.first][top.second] == 0){
    //             continue;
    //         }
    //         ans++;
    //         grid[top.first][top.second] = 0;
    //         if((top.first-1 >= 0) && (grid[top.first-1][top.second]==1)){
    //             q.push({top.first-1 ,top.second});
    //         }
    //         if((top.second-1 >= 0) && (grid[top.first][top.second-1]==1)){
    //             q.push({top.first ,top.second-1});
    //         }
    //         if((top.first+1 < n) && (grid[top.first+1][top.second]==1)){
    //             q.push({top.first+1 ,top.second});
    //         }
    //         if((top.second+1 < m) && (grid[top.first][top.second+1]==1)){
    //             q.push({top.first ,top.second+1});
    //         }
    //     }
    //     // cout<<flag<<" "<<ans<<endl;
    //     return flag == 0 ? ans : 0;
    // }
    // int numEnclaves(vector<vector<int>>& grid) {
    //     int n = grid.size() , m = grid[0].size() , ans = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j] == 1){
    //                 ans+=solve(i , j , grid , n , m);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    
    // Solving it again, simple using BFS and storing boundary elements in queue
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                q.push({i , 0});
            }
            if(grid[i][m-1] == 1){
                q.push({i , m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                q.push({0 , i});
            }
            if(grid[n-1][i] == 1){
                q.push({n-1 , i});
            }
        }
        // cout<<q.size()<<"sz"<<endl;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first , j = top.second;
            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }
            if(grid[i][j] == 0){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            q.push({i+1 , j});
            q.push({i-1 , j});
            q.push({i , j-1});
            q.push({i , j+1});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};