//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V , INT_MAX);
        vector<bool> vis(V , false);
        set<pair<int,int>> st;
        st.insert({0 , S});
        dis[S] = 0;
        while(st.size() > 0){
            auto top = *st.begin();
            int ver = top.second;
            int dist = top.first;
            st.erase(st.begin());
            if(vis[ver]){
                continue;
            }
            vis[ver] = true;
            for(auto it: adj[ver]){
                // for(auto i: it){
                    int childV = it[0];
                    int childD = it[1];
                    if(dis[childV] > dist+childD){
                        dis[childV] = dist+childD;
                        st.insert({dis[childV] , childV });
                    }
                // }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends