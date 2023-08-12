class Solution {
public:
    
    // By finding no of connected compoents using DFS
    
//     void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
//     {
//         visited[src] = true;
//         for(int i : adj[src])
//             if(!visited[i])
//                 dfs(adj, visited, i);
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
        
//         if(connections.size() < n - 1)
//             return -1;
//         vector<vector<int>> adj(n);
//         for(auto v : connections)
//         {
//             adj[v[0]].push_back(v[1]);
//             adj[v[1]].push_back(v[0]);
//         }
//         vector<bool> visited(n, false);
//         int components = 0;
//         for(int i=0; i<n; i++)
//             if(!visited[i])
//             {
//                 dfs(adj, visited, i);
//                 components++;
//             }
//         return components - 1;
//     }
    
    
    
    
    // Now by DSU
public:
    class DisjointSet{
        private:
        vector<int> parent , size;
        public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1 , 1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return;
            }
            if(size[parU] >= size[parV]){
                parent[parV] = parU;
                size[parU] += size[parV];
            }else{
                parent[parU] = parV;
                size[parV] += size[parU];
            }
            return;
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet s(n);
        int sz = connections.size();
        for(auto it: connections){
            s.unionBySize(it[0] , it[1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s.findParent(i) == i){
                ans++;
            }
        }
        if(sz < n-1){
            return -1;
        }
        return ans-1; 
    }
};