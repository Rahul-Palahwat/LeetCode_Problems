class Solution {
public:
    int parent[1000], size[1000];
    void make(){
        for(int i=0;i<1000;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int a){
        if(parent[a]==a)
            return a;
        return parent[a] = find(parent[a]);
    }
    
    void Union(int a, int b){
        a = find(a), b = find(b);
        if(a!=b){
            if(size[a] < size[b])
                swap(a, b);
            
            size[a] += size[b];
            parent[b] = a;
        }
    }
    
    int kruskal(vector<vector<int>> &edges){
        sort(edges.begin(), edges.end());
        int res = 0;
        make();
        for(auto &i:edges){
            int u = i[1], v = i[2], w = i[0];
            if(find(u)!=find(v)){
                Union(u,v);
                res += w;
            }
        }
        
        return res;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    edges.push_back({abs(points[i][0]-points[j][0]) +
                        abs(points[i][1]-points[j][1]), i, j});
            }
        }
        
        return kruskal(edges);
    }
};