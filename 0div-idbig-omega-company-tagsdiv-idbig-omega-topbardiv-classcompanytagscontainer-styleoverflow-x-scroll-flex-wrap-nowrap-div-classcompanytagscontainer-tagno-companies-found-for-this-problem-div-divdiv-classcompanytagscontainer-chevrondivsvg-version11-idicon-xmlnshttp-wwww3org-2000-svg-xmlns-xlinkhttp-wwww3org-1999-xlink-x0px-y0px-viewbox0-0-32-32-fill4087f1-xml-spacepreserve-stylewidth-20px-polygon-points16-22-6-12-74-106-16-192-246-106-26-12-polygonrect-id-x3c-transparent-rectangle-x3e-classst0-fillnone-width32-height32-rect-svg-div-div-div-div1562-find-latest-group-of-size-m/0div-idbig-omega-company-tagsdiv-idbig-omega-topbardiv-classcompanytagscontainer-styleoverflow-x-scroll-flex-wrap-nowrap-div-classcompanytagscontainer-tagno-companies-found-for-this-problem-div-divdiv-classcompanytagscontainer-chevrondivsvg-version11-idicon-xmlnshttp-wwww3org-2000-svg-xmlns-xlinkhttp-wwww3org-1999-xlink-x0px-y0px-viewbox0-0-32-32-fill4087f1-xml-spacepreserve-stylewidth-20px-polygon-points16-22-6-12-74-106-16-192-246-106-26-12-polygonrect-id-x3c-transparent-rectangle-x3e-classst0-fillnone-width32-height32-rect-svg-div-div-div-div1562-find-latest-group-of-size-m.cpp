class DisjointSet{
        public:
        vector<int> parent , size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1 , 1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
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
            return;
        }
    };
class Solution {
public:
    
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<bool> vis(n+2 , false);
        int ans = -1;
        DisjointSet dsu(n);
        for(int i=0;i<n;i++){
            if(arr[i] > 1){
                if(vis[arr[i]-1]){
                    int par = dsu.findParent(arr[i]-1);
                    if(dsu.size[par] == m){
                        // cout<<i<<" ansP ";
                        ans = i;
                    }
                    dsu.unionBySize(arr[i] , arr[i]-1);
                }
                
            }
            if(arr[i] < n){
                if(vis[arr[i]+1]){
                    int par = dsu.findParent(arr[i]+1);
                    if(dsu.size[par] == m){
                        // cout<<i<<" ansn ";
                        ans = i;
                    }
                    dsu.unionBySize(arr[i] , arr[i]+1);
                }
                
            }
            int par = dsu.findParent(arr[i]);
            if(dsu.size[par] == m){
                // cout<<i<<" ans1 ";
                ans = i+1;
            }
            vis[arr[i]] = true;
            // for(int i=1;i<=n;i++){
            //     int par = dsu.findParent(i);
            //     cout<<par<<" sz-> ";
            //     cout<<dsu.size[par]<<" ";
            // }
            // cout<<endl;
        }
        // cout<<endl;
        return ans;
    }
};



