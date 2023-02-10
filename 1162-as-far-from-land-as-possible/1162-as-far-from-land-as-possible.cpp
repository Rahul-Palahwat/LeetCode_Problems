class Solution {
public:
    queue<vector<int>> q;
    int n , m;
    int ans=-1;
    void solve(vector<vector<int>>& grid){
        
        while(q.size() > 0){
            int t = q.size();
        // cout<<t<<"size"<<endl;
        
        while(t--){
            auto top = q.front();
            q.pop();
            int i = top[0];
            int j = top[1];
            int dis = top[2];
            ans = dis;
            // cout<<t<<" t "<<dis<<endl;
            if(i+1 < n && grid[i+1][j] == 0){
                q.push({i+1 , j , dis+1});
                grid[i+1][j] = 1;
            }
            if(i-1 >= 0 && grid[i-1][j] == 0){
                q.push({i-1 , j , dis+1});
                grid[i-1][j] = 1;
            }
            if(j+1 < m && grid[i][j+1] == 0){
                q.push({i , j+1 , dis+1});
                grid[i][j+1] = 1;
            }
            if(j-1 >=0 && grid[i][j-1] == 0){
                q.push({i , j-1 , dis+1});
                grid[i][j-1] = 1;
            }
        }
        }
        return;
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i ,j ,0});
                }
            }
        }
        solve(grid);
        return ans==0 ? -1 : ans;
    }
};