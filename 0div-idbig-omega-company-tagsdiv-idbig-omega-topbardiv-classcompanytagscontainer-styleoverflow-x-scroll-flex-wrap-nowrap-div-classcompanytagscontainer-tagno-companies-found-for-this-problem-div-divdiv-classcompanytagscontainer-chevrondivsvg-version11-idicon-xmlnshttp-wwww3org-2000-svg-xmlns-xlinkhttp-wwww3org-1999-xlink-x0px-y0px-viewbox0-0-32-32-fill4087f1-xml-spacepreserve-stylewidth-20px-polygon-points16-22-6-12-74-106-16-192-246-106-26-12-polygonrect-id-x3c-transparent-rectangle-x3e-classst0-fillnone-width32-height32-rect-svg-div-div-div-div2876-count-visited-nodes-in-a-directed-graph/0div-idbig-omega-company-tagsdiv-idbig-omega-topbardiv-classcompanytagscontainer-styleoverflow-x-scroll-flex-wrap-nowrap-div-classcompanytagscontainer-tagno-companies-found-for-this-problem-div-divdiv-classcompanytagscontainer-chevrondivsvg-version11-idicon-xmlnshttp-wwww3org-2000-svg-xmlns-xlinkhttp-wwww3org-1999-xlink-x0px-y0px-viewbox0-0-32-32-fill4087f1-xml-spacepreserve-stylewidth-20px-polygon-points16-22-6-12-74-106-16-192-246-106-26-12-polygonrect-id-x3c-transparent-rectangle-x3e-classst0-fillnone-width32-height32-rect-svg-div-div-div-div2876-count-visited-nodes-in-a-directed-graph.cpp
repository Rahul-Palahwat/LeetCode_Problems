class Solution {
public:
    // int loop = -1;
    // int findMaxi(int node , vector<int> &edges , vector<bool> &vis){
    //     if(vis[node]){
    //         return 0;
    //     }
    //     vis[node] = true;
    //     int dis = 1+findMaxi(edges[node] , edges , vis);
    //     return dis;
    // }
    // int dfs(int node , vector<int> &edges , vector<bool> &vis , vector<int> &ans , vector<bool> &temp){
    //     if(temp[node]){
    //         loop = node;
    //         return max(ans[node]-1,0);
    //     }
    //     temp[node] = true;
    //     vis[node] = true;
    //     int dis = 1+dfs(edges[node] , edges , vis , ans , temp);
    //     temp[node] = false;
    //     return ans[node] = dis;
    // }
    // vector<int> countVisitedNodes(vector<int>& edges) {
    //     int n = edges.size();
    //     vector<int> ans(n , 0);
    //     vector<bool> vis(n , false);
    //     vector<bool> temp(n , false);
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             ans[i] = max(ans[i] , dfs(i , edges , vis, ans , temp));
    //         }
    //     }
    //     if(loop != -1){
    //         vector<bool> temp(n , false);
    //         int dis = findMaxi(loop , edges , temp);
    //         cout<<loop<<" Loop "<<dis<<endl;
    //         for(int i=0;i<n;i++){
    //             cout<<temp[i]<<" "<<i<<endl;
    //             if(temp[i]){
    //                 ans[i] = dis;
    //             }
    //         }
    //     }
    //     cout<<endl;
    //     return ans;
    // }
    
    
    
    vector<int> countVisitedNodes(vector<int>& edges) {
    int n = edges.size();
        vector<int> res(n);
        for (int i = 0, j = 0; i < n; j = ++i) {
            set<int> seen;
            vector<int> s;
            while (!seen.count(j) && res[j] == 0) {
                seen.insert(j);
                s.push_back(j);
                j = edges[j];
            }
            if (seen.count(j)) { // hit the cycle
                int k = distance(find(s.begin(), s.end(), j), s.end());
                for (j = 0; j < k; ++j) {
                    res[s.back()] = k;
                    s.pop_back();
                }
            }
            while (!s.empty()) {
                j = s.back();
                s.pop_back();
                res[j] = res[edges[j]] + 1;
            }
        }
        return res;
    }
};