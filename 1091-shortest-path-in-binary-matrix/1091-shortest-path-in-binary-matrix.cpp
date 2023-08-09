class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;
                if(i<0 || j<0 || i>=n || j>=m){
                    continue;
                }
                if(grid[i][j] == 1 || vis[i][j]){
                    continue;
                }
                if(i == n-1 && j == m-1){
                    cout<<i<<" i "<<j<<endl;
                    return ans;
                }
                vis[i][j] = true;
                for(int x=-1;x<=1;x++){
                    for(int y = -1;y<=1;y++){
                        q.push({i+x , j+y});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};