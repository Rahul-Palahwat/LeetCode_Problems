class Solution {
public:
    bool solve(vector<int> g[],int node,vector<bool> &vis , vector<int> &col){
        queue<int> q;
        q.push(node);
        col[node] = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            vis[t] = true;
            for(auto it: g[t]){
                if(vis[it] == true){
                    if(col[it] == col[t]){
                        return false;
                    }
                    continue;
                }
                q.push(it);
                if(col[t] == 1){
                    col[it] = 2;
                }else{
                    col[it] = 1;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        for(auto it: dislikes){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n+1,0);
        vector<int> col(n+1,0);
        bool ans = true;
        for(int i=1;i<=n;i++){
            if(vis[i] == false){
                ans = ans && solve(g,i,vis,col);
            }
        }
        return ans;
    }
    
};