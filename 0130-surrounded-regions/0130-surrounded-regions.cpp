class Solution {
public:
    // In this question, take the O's of boundary and then perform BFS on them
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                q.push({i  , 0});
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                q.push({0 , i});
            }
            
            if(board[n-1][i] == 'O'){
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
            if(board[i][j] == 'X'){
                continue;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            q.push({i-1 , j });
            q.push({i+1 , j});
            q.push({i , j+1});
            q.push({i , j-1});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};