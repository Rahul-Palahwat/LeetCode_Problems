class Solution {
public:
//     bool solve(int node, vector<bool>& vis , vector<int>& col,vector<vector<int>>& graph){
//         stack<pair<int,int>> q;
//         q.push({node , -1});
//         while(!q.empty()){
//             int n = q.top().first;
//             int c = q.top().second;
//             q.pop();
//             vis[n] = true;
//             if(c == -1){
//                 col[n] = 0;
//             }else if(c == 0){
//                 col[n] = 1;
//             }else{
//                 col[n] = 0;
//             }
//             for(auto it: graph[n]){
//                 if(vis[it]){
//                     if(col[it] == col[n]){
//                         // cout<<col[it]<<"Hello"<<col[n]<<" "<<it<<" "<<n<<endl;
//                         return true;
//                     }
//                     continue;
//                 }
//                 q.push({it , col[n]});
//             }
            
//         }
//         return false;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<bool> vis(n,false);
//         vector<int> col(n,-1);
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 if(solve(i , vis , col , graph)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
    
    
//     // Another try using bfs
//     bool check(int node , vector<vector<int>>&graph , vector<bool> &vis , vector<int>& col){
//         queue<pair<int, int>> q;
//         q.push({node , 0});
//         while(!q.empty()){
//             auto top = q.front();
//             q.pop();
//             int color = top.second;
//             vis[top.first] = true;
//             col[top.first] = color;
//             for(auto it: graph[top.first]){
//                 if(vis[it]){
//                     if(col[it] == color){
//                         return false;
//                     }
//                     continue;
//                 }
//                 if(color == 0){
//                     q.push({it , 1});
//                 }else{
//                     q.push({it , 0});
//                 }
                
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<bool> vis(n , false);
//         vector<int> col(n , -1);
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 if(!check(i , graph , vis , col)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
    
    // Another try using dfs
    // bool dfs(int node, int color , vector<vector<int>>& graph , vector<bool>&vis , vector<int>&col){
    //     vis[node] = true;
    //     col[node] = color;
    //     bool ans = true;
    //     for(auto it: graph[node]){
    //         if(vis[it]){
    //             if(col[it] == color){
    //                 return false;
    //             }
    //             continue;
    //         }
    //         if(color == 1){
    //             ans = (ans && dfs(it , 0 , graph , vis , col));
    //         }else{
    //             ans = (ans && dfs(it , 1 , graph , vis , col));
    //         }
    //     }
    //     return ans;
    // }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<bool> vis(n , false);
    //     vector<int> col(n , -1);
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             if(!dfs(i , 0 , graph , vis , col)){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // ONE MORE TRY
    bool isPossible(int node , vector<vector<int>>& g, vector<int>& col , vector<bool>&vis){
        queue<pair<int,int>> q;
        q.push({node , 0});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int ver = top.first;
            int color = top.second;
            if(vis[ver]){
                continue;
            }
            col[ver] = color;
            vis[ver] = true;
            for(auto it: g[ver]){
                if(color == 1){
                    if(col[it] == 1){
                        return false;
                    }
                    q.push({it, 0});
                }else{
                    if(col[it] == 0){
                        return false;
                    }
                    q.push({it, 1});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n , false);
        vector<int> col(n , -1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!isPossible(i , graph , col , vis)){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
};