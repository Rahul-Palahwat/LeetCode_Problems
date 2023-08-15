class DSU{
    private:
    vector<int> parent , size;
    public:
    DSU(int n){
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
    int sizeNode(int node){
        return size[node];
    }
};
class Solution {
public:
    bool isValid(int x , int y , int n , int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n*m;
        DSU dsu(sz);
        vector<int> dx = {1 , -1 , 0, 0};
        vector<int> dy = {0 , 0 , -1 , 1};
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int node = i*n + j;
                    for(int k=0;k<4;k++){
                        int tempX = i+dx[k];
                        int tempY = j+dy[k];
                        if(isValid(tempX , tempY , n , m) && grid[tempX][tempY]){
                            // cout<<tempX<<" tempX "<<tempY<<endl;
                            // cout<<i<<" i "<<j<<endl;
                            int tempNode = tempX*n + tempY;
                            dsu.unionBySize(node , tempNode);
                        }
                    }
                    int parentTemp = dsu.findParent(node);
                    ans = max(ans , dsu.sizeNode(parentTemp));
                }
            }
        }
        // for(int i=0;i<sz;i++){
        //     cout<<dsu.sizeNode(i)<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    int tempAns = 1;
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int tempX = i+dx[k];
                        int tempY = j+dy[k];
                        if(isValid(tempX , tempY , n , m) && grid[tempX][tempY]){
                            int tempNode = tempX*n + tempY;
                            int parTemp = dsu.findParent(tempNode);
                            st.insert(parTemp);
                           // tempAns+=dsu.sizeNode(parTemp);
                        }
                    }
                    for(auto it: st){
                        tempAns+=dsu.sizeNode(it);
                    }
                    ans = max(ans , tempAns);
                }
            }
        }
        return ans;
    }
};