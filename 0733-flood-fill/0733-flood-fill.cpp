class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int col = image[sr][sc];
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        queue<vector<int>> q;
        q.push({sr , sc , color , col});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top[0] , j = top[1];
            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            if(image[i][j] == top[3]){
                image[i][j] = top[2];
                q.push({i+1 , j , top[2] , top[3]});
                q.push({i-1 , j , top[2] , top[3]});
                q.push({i , j+1 , top[2] , top[3]});
                q.push({i , j-1 , top[2] , top[3]});
            }
        }
        return image;
    }
};