//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> ans;
        vector<pair<int,int>> g[n+1];
        for(auto it: edges){
            g[it[0]].push_back({it[1] , it[2]});
            g[it[1]].push_back({it[0] , it[2]});
        }
        vector<int> parent(n+1 , 0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        vector<int> dis(n+1 , INT_MAX);
        vector<bool> vis(n+1 , false);
        set<pair<int,int>> st;
        st.insert({0 , 1});
        dis[1] = 0;
        while(st.size() > 0){
            auto top = *st.begin();
            st.erase(st.begin());
            int node = top.second;
            if(vis[node]){
                continue;
            }
            vis[node] = true;
            for(auto it: g[node]){
                int nd = it.first;
                int d = it.second;
                if(dis[nd] > d+dis[node]){
                    dis[nd] = d+dis[node];
                    st.insert({dis[nd] , nd});
                    parent[nd] = node;
                }
            }
        }
        int par = n;
        while(1){
            if(parent[par] == 1 && par == 1){
                ans.push_back(par);
                reverse(ans.begin() , ans.end());
                return ans;
            }
            if(parent[par] == par){
                return {-1};
            }
            ans.push_back(par);
            par = parent[par];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends