//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(vector<pair<int,int>> g[],vector<bool> &vis , vector<int> &dis, int source){
        set<pair<int,int>> st;
        st.insert({0,source});
        dis[source] = 0;
        while(st.size() > 0){
            auto t = *st.begin();
            st.erase(st.begin());
            if(vis[t.second]){
                continue;
            }
            vis[t.second] = 1;
            for(auto child: g[t.second]){
                int child_v = child.first;
                int w_v = child.second;
                if(dis[t.second]+w_v < dis[child_v]){
                    dis[child_v] = dis[t.second]+w_v;
                    st.insert({dis[child_v], child_v});
                }
            }
        }
    }
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<int> dis(n+1,INT_MAX);
        vector<bool> vis(n+1,0);
        vector<pair<int,int>> g[n+1];
        for(auto it: flights){
            g[it[0]].push_back({it[1],it[2]});
        }
        solve(g,vis,dis,k);
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends