class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 1e5));
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i , j , 0});
                }
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top[0] , j = top[1] , dis = top[2];
            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            ans[i][j] = min(ans[i][j] , dis);
            q.push({i+1 , j , dis+1});
            q.push({i-1 , j , dis+1});
            q.push({i , j+1 , dis+1});
            q.push({i , j-1 , dis+1});
        }
        return ans;
    }
};