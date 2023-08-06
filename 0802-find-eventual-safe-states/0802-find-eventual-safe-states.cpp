class Solution {
public:
    bool dfs(int node, vector<vector<int>>&g, vector<bool>&vis, vector<bool>&pathVis, vector<bool>&check){
        vis[node] = true;
        pathVis[node] = true;
        check[node] = false;
        for(auto it: g[node]){
            if(!vis[it]){
                if(dfs(it , g , vis , pathVis , check)){
                    check[node] = false;
                    return true;
                }
            }else if(pathVis[it]){
                check[node] = false;
                return true;
            }
        }
        check[node] = true;
        pathVis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n , false);
        vector<bool> pathVis(n , false);
        vector<bool> check(n , false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , graph , vis , pathVis, check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};