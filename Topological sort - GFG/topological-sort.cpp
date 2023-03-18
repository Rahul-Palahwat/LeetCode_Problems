//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	using DFS
	//Function to return list containing vertices in Topological order.
// 	vector<int> ans;
// 	void dfs(int node , vector<int> adj[], vector<bool>& vis){
// 	    if(vis[node]){
// 	        return;
// 	    }
// 	    vis[node] = true;
// 	    for(auto it: adj[node]){
// 	        dfs(it , adj,vis);
// 	    }
// 	    ans.push_back(node);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    vector<bool> vis(V,false);
// 	    for(int i=0;i<V;i++){
// 	        if(!vis[i]){
// 	            dfs(i , adj,vis);
// 	        }
// 	    }
// 	    reverse(ans.begin() , ans.end());
// 	    return ans;
// 	}
	
	
	
// 	Now using BFS
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            indeg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i] == 0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        for(auto it: adj[top]){
	            indeg[it]--;
	            if(indeg[it] == 0){
	                q.push(it);
	            }
	        }
	        ans.push_back(top);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends