class DisjointSet{
    private:
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1 , 0);
        size.resize(n+1 , 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return findParent(parent[node]);
    }
    
    bool UnionBySize(int x, int y){
        int parX = findParent(x);
        int parY = findParent(y);
        if(parX == parY){
            return false;
        }
        if(size[parX] >= size[parY]){
            parent[parY] = parX;
            size[parX]+=size[parY];
        }else{
            parent[parX] = parY;
            size[parY]+=size[parX];
        }
        return true;
    }
    int findSize(int x){
        return size[x];
    }
};
class Solution {
public:
    void dfs(int node, vector<pair<int,int>> g[], vector<bool> &vis, int color){
        if(vis[node]){
            return;
        }
        vis[node] = true;
        for(auto it: g[node]){
            if(it.second == 3 || it.second == color){
                dfs(it.first , g , vis , color);
            }
        }
        return;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        int sz = edges.size();
        int ans = 0;
        DisjointSet dsuAlice(n), dsuBob(n);
        for(int i=sz-1;i>=0;i--){
            int x = edges[i][1] , y = edges[i][2];
            if(edges[i][0] == 3){
                if(dsuAlice.UnionBySize(x , y)){
                    dsuBob.UnionBySize(x , y);
                }else{
                    ans++;
                }
            }else if(edges[i][0] == 2){
                if(!dsuBob.UnionBySize(x , y)){
                    ans++;
                }
            }else{
                if(!dsuAlice.UnionBySize(x , y)){
                    ans++;
                }
            }
        }
        int parAlice = dsuAlice.findParent(1);
        int sizeAlice = dsuAlice.findSize(parAlice);
        int parBob = dsuBob.findParent(1);
        int sizeBob = dsuBob.findSize(parBob);
        cout<<sizeAlice<<" "<<sizeBob<<endl;
        if(sizeAlice == n && sizeBob == n){
            return ans;
        }
        return -1;
    }
};