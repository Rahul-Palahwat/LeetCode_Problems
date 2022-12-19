class Solution {
public:
    bool solve(vector<int> g[],vector<bool> vis, int s, int d){
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int t = q.front();
            vis[t]=1;
            q.pop();
            for(auto it: g[t]){
                if(it == d){
                    return true;
                }
                if(vis[it] == 0)
                q.push(it);
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        if(source == destination){
            return true;
        }
        vector<bool> vis(n,0);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        return solve(graph,vis,source,destination);
        
    }
};