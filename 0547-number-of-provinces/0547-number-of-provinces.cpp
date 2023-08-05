class Solution {
public:
    // void bfs(int node , vector<int> g[] , vector<bool>& vis){
    //     queue<int> q;
    //     q.push(node);
    //     while(!q.empty()){
    //         int t = q.front();
    //         q.pop();
    //         vis[t] = true;
    //         for(auto it: g[t]){
    //             if(!vis[it]){
    //                 q.push(it);
    //             }
    //         }
    //     }
    //     return;
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int ans = 0;
    //     int n = isConnected.size();
    //     int m = isConnected[0].size();
    //     vector<int> g[n+1];
    //     vector<bool> vis(n+1 , false);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(isConnected[i][j] == 1){
    //                 g[i+1].push_back(j+1);
    //                 g[j+1].push_back(i+1);
    //             }
    //         }
    //     }
    //     for(int i=1;i<=n;i++){
    //         if(!vis[i]){
    //             ans++;
    //             bfs(i , g , vis);
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    
    
    
    
    // New try
    void dfs(int node , vector<int> g[] , vector<bool> &vis){
        vis[node] = true;
        for(auto it: g[node]){
            if(!vis[it]){
                dfs(it , g , vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> g[n+1];
        vector<bool> vis(n+1 , false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1){
                    g[i+1].push_back(j+1);
                    g[j+1].push_back(i+1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                // cout<<i<<" i "<<endl;
                ans++;
                dfs(i , g , vis);
            }
        }
        return ans;
    }
};