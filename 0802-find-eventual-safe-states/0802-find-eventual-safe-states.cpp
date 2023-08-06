class Solution {
public:
    
    
    // using DFS for undirected graph
    
    // bool dfs(int node, vector<vector<int>>&g, vector<bool>&vis, vector<bool>&pathVis, vector<bool>&check){
    //     vis[node] = true;
    //     pathVis[node] = true;
    //     check[node] = false;
    //     for(auto it: g[node]){
    //         if(!vis[it]){
    //             if(dfs(it , g , vis , pathVis , check)){
    //                 check[node] = false;
    //                 return true;
    //             }
    //         }else if(pathVis[it]){
    //             check[node] = false;
    //             return true;
    //         }
    //     }
    //     check[node] = true;
    //     pathVis[node] = false;
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<bool> vis(n , false);
    //     vector<bool> pathVis(n , false);
    //     vector<bool> check(n , false);
    //     vector<int> ans;
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             dfs(i , graph , vis , pathVis, check);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(check[i]){
    //             ans.push_back(i);
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    // Now using topological sort using Kahn's algo (BFS)
    // For this question, reverse all the edges
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> g[n];
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                g[it].push_back(i);
            }
        }
        vector<int> indegree(n , 0);
        for(int i=0;i<n;i++){
            for(auto it: g[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it: g[top]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};