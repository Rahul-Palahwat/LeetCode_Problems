//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> g[N];
        for(auto it: edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> ans(N , INT_MAX);
        vector<bool> vis(N , false);
        set<pair<int,int>> st;
        st.insert({0 , src});
        ans[src] = 0;
        while(st.size() > 0){
            auto top = *st.begin();
            st.erase(st.begin());
            int node = top.second;
            int d = top.first;
            if(vis[node]){
                continue;
            }
            for(auto it: g[node]){
                if(ans[it] > 1+ans[node]){
                    ans[it] = 1+ans[node];
                    st.insert({ans[it] , it});
                }
            }
        }
        for(auto &it : ans){
            if(it == INT_MAX){
                it = -1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends