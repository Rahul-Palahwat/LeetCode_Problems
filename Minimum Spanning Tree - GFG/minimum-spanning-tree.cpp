//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        set<pair<int,pair<int,int>>> st;
        vector<bool> vis(V , false);
        st.insert({0 , {0 , -1}});
        vector<pair<int,int>> edges;
        int sum = 0;
        while(st.size() > 0){
            auto top = *st.begin();
            st.erase(st.begin());
            int node = top.second.first;
            int parent = top.second.second;
            int wt = top.first;
            if(vis[node]){
                continue;
            }
            vis[node] = true;
            sum+=wt;
            if(parent != -1){
                edges.push_back({node , parent});
            }
            for(auto it: adj[node]){
                st.insert({it[1] , {it[0] , node}});
            }
        }
        return sum;
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