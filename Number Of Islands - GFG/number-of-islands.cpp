//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    private:
    vector<int> parent , size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1 , 1);
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
    void unionBySize(int u , int v){
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
        return;
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        int sz = m*n;
        
        DisjointSet DS(sz);
        vector<vector<int>> matrix(n , vector<int>(m , 0));
        vector<int> vis(sz , false);
        for(auto it: operators){
            int u = it[0];
            int v = it[1];
            if(matrix[u][v]){
                ans.push_back(ans.back());
                continue;
            }
            matrix[u][v] = 1;
            int node = u*m + v;
            if(u-1 >= 0 && matrix[u-1][v]){
                int neighbour = (u-1)*m + v;
                DS.unionBySize(node , neighbour);
            }
            if(v-1 >= 0 && matrix[u][v-1]){
                int neighbour = (u)*m + v-1;
                DS.unionBySize(node , neighbour);
            }
            if(u+1 < n && matrix[u+1][v]){
                int neighbour = (u+1)*m + v;
                DS.unionBySize(node , neighbour);
            }
            if(v+1 < m && matrix[u][v+1]){
                int neighbour = (u)*m + v + 1;
                DS.unionBySize(node , neighbour);
            }
            vis[node] = true;
            int cnt = 0;
            for(int i=0;i<sz;i++){
                if(vis[i] && DS.findParent(i) == i){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends