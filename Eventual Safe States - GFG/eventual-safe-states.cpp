//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node , vector<bool>&vis , vector<bool>&temp, vector<bool>&loop , vector<int> g[]){
        if(temp[node]){
            loop = temp;
            return true;
        }
        temp[node] = true;
        vis[node] = true;
        bool ans = false;
        for(auto it: g[node]){
            ans = ans || dfs(it , vis , temp , loop , g);
        }
        temp[node] = false;
        return ans;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V , false);
        vector<bool> ansBool(V , false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<bool> temp(V , false);
                vector<bool> loop(V , false);
                if(dfs(i , vis , temp , loop , adj)){
                    for(int i=0;i<V;i++){
                        ansBool[i] = ansBool[i] || loop[i];
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!ansBool[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends