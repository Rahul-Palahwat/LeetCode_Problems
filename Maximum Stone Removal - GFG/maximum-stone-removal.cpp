//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSetUnion{
    private:
    vector<int> parent , size;
    public:
    DisjointSetUnion(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        if(parU == parV){
            return;
        }
        if(size[parU] >= size[parV]){
            parent[parV] = parU;
            size[parU] += size[parV];
        }else{
            parent[parU] = parV;
            size[parV] += size[parU];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0 , maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }
        DisjointSetUnion dsu(maxRow+maxCol+1);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int u = it[0];
            int v = it[1]+ maxRow+1;
            dsu.unionBySize(u , v);
            mp[u] = 1;
            mp[v] = 1;
        }
        int components = 0;
        for(auto it: mp){
            if(dsu.findParent(it.first) == it.first){
                components++;
            }
        }
        return n - components;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends