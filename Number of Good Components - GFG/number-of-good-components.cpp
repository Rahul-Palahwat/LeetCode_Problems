//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int v , vector<vector<int>> &g , vector<int>& mp , vector<bool>& vis){
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(vis[top]){
                continue;
            }
            // cout<<top<<" top"<<endl;
            vis[top] = true;
            mp.push_back(top);
            for(auto it: g[top]){
                q.push(it);
            }
        }
        return;
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& g) {
        // code here
        int ans = 0;
        vector<bool> vis(V+1 , false);
        for(int i=1;i<=V;i++){
            vector<int> mp;
            if(vis[i]){
                continue;
            }
            // cout<<i<<" going to solve"<<endl;
            solve(i , g , mp , vis);
            int flag = 0;
            // cout<<mp.size()<<" size"<<endl;
            int n = mp.size()-1;
            for(auto it: mp){
                if(g[it].size() < n){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans++;
                // cout<<i<<" v"<<endl;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends