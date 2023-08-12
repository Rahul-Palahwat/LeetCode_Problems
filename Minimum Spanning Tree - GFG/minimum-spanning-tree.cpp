//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	
// 	Using prim's algorithm

    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     // code here
    //     set<pair<int,pair<int,int>>> st;
    //     vector<bool> vis(V , false);
    //     st.insert({0 , {0 , -1}});
    //     vector<pair<int,int>> edges;
    //     int sum = 0;
    //     while(st.size() > 0){
    //         auto top = *st.begin();
    //         st.erase(st.begin());
    //         int node = top.second.first;
    //         int parent = top.second.second;
    //         int wt = top.first;
    //         if(vis[node]){
    //             continue;
    //         }
    //         vis[node] = true;
    //         sum+=wt;
    //         if(parent != -1){
    //             edges.push_back({node , parent});
    //         }
    //         for(auto it: adj[node]){
    //             st.insert({it[1] , {it[0] , node}});
    //         }
    //     }
    //     return sum;
    // }
    
    
// Using kruskal's algorith with DSU
    class DisjointSet{
        private:
        vector<int> parent , size;
        public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        bool unionBySize(int u , int v){
            int parU = findParent(u);
            int parV = findParent(v);
            if(parU == parV){
                return false;
            }
            if(size[parU] >= size[parV]){
                parent[parV] = parU;
                size[parU]+=size[parV];
            }else{
                parent[parU] = parV;
                size[parV]+=size[parU];
            }
            return true;
        }
    };
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet s(V);
        set<pair<int, pair<int,int>>> st;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                st.insert({it[1] , {it[0] , i}});
            }
        }
        int ans = 0;
        while(st.size() > 0){
            auto top = *st.begin();
            st.erase(st.begin());
            int wt = top.first;
            int u = top.second.first;
            int v = top.second.second;
            if(s.unionBySize(u , v)){
                ans+=wt;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends