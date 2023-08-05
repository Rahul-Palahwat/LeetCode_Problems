class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int col = image[sr][sc];
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        vector<vector<int>> ans = image;
        queue<pair<int,int>> q;
        q.push({sr , sc});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first , j = top.second;
            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            if(ans[i][j] == col){
                ans[i][j] = color;
                q.push({i+1 , j});
                q.push({i-1 , j });
                q.push({i , j+1});
                q.push({i , j-1});
            }
        }
        return ans;
    }
};