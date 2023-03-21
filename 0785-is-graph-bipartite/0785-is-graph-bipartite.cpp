class Solution {
public:
    bool solve(int node, vector<bool>& vis , vector<int>& col,vector<vector<int>>& graph){
        stack<pair<int,int>> q;
        q.push({node , -1});
        while(!q.empty()){
            int n = q.top().first;
            int c = q.top().second;
            q.pop();
            vis[n] = true;
            if(c == -1){
                col[n] = 0;
            }else if(c == 0){
                col[n] = 1;
            }else{
                col[n] = 0;
            }
            for(auto it: graph[n]){
                if(vis[it]){
                    if(col[it] == col[n]){
                        // cout<<col[it]<<"Hello"<<col[n]<<" "<<it<<" "<<n<<endl;
                        return true;
                    }
                    continue;
                }
                q.push({it , col[n]});
            }
            
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(solve(i , vis , col , graph)){
                    return false;
                }
            }
        }
        return true;
    }
};