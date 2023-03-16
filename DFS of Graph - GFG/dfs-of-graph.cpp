//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    // vector<int> ans;
    // void dfs(int i , vector<int> adj[] , vector<bool>& vis){
    //     if(vis[i]){
    //         return;
    //     }
    //     vis[i] = true;
    //     ans.push_back(i);
    //     for(auto it: adj[i]){
    //         dfs(it , adj , vis);
    //     }
    //     return;
    // }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        stack<int> q;
        vector<bool> vis(V,false);
        // dfs(0 , adj , vis);
        q.push(0);
        while(!q.empty()){
            // int t = q.size();
            // while(t--){
            int top = q.top();
            q.pop();
            if(vis[top]){
                continue;
            }
            vis[top] = true;
            ans.push_back(top);
            vector<int> temp;
            for(auto it: adj[top]){
                // q.push(it);
                temp.push_back(it);
            }
            reverse(temp.begin() , temp.end());
            for(auto it: temp){
                q.push(it);
            }
            // }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends