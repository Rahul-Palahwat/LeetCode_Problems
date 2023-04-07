class Solution {
public:
    int solve(int i , int j ,vector<vector<int>>& grid ,int n ,int m){
        queue<pair<int,int>> q;
        q.push({i , j});
        int ans = 0,flag=0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if((top.first <= 0) || (top.second <= 0)){
                flag=1;
                // return 0;
            }
            if((top.first >= (n-1)) || (top.second >= (m-1))){
                flag=1;
                // return 0;
            }
            if(grid[top.first][top.second] == 0){
                continue;
            }
            ans++;
            cout<<top.first<<" "<<top.second<<endl;
            grid[top.first][top.second] = 0;
            if((top.first-1 >= 0) && (grid[top.first-1][top.second]==1)){
                q.push({top.first-1 ,top.second});
            }
            if((top.second-1 >= 0) && (grid[top.first][top.second-1]==1)){
                q.push({top.first ,top.second-1});
            }
            if((top.first+1 < n) && (grid[top.first+1][top.second]==1)){
                q.push({top.first+1 ,top.second});
            }
            if((top.second+1 < m) && (grid[top.first][top.second+1]==1)){
                q.push({top.first ,top.second+1});
            }
        }
        // cout<<flag<<" "<<ans<<endl;
        return flag == 0 ? ans : 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ans+=solve(i , j , grid , n , m);
                }
            }
        }
        return ans;
    }
};