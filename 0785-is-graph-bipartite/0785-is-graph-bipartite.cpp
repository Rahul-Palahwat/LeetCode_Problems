class Solution {
public:
    bool solve(int index ,vector<bool>& vis ,  vector<int> g[], vector<int>& col){
        queue<int> q;
        q.push(index);
        col[index] = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            vis[t] = true;
            for(auto it: g[t]){
                if(col[it] == col[t]){
                    return false;
                }else{
                    if(vis[it] == true){
                        continue;
                    }
                    q.push(it);
                    if(col[t] == 1){
                        col[it] =0;
                    }else{
                        col[it]=1;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,-1);
        vector<int> g[n];
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                g[i].push_back(it);
            }
        }
        bool ans = true;
        for(int i=0;i<n;i++){
            if(vis[i] == false){
                ans = ans && solve(i,vis,g,col);
            }
        }
        return ans;
        
    }
};