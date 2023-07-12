class Solution {
public:
    // void dfs(vector<bool> &vis , vector<int>& ans , int node, vector<vector<int>>& graph){
    //     if(vis[node]){
    //         return;
    //     }
    //     vis[node] = true;
    //     possible[node] = false;
    //     for(auto it: graph[node]){
    //         dfs(vis , ans, it, graph);
    //     }
    //     possible[node] = true;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<int> ans;
    //     vector<bool> vis(n , false);
    //     vector<bool> possible(n , false);
    //     for(int i=1;i<n;i++){
    //         if(vis[i] == false){
    //             dfs(vis , ans , i, graph);
    //         }
    //     }
    //     sort(ans.begin() , ans.end());
    //     return ans;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
    int N = G.size();
    vector<vector<int>> R(N);
    vector<int> outdegree(N), safe(N), ans;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        for (int v : G[i]) {
            R[v].push_back(i);
        }
        outdegree[i] = G[i].size();
        if (outdegree[i] == 0) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        safe[u] = 1;
        for (int v : R[u]) {
            if (--outdegree[v] == 0) q.push(v);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (safe[i]) ans.push_back(i);
    }
    return ans;
}
};