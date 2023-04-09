class Solution {
// public:
    // int findMaxi(string s){
    //     int ans = 0;
    //     unordered_map<char , int> mp;
    //     for(auto it: s){
    //         mp[it]++;
    //     }
    //     for(auto it: mp){
    //         ans = max(ans , it.second);
    //     }
    //     return ans;
    // }
    // int solve(int node , vector<int> g[] , string colors, vector<string>& dp){
    //     int ans = 0;
    //     queue<pair<int,string>> q;
    //     string s="";
    //     s+=colors[node];
    //     q.push({node , s});
    //     while(!q.empty()){
    //         int t = q.size();
    //         while(t--){
    //             auto top = q.front();
    //             q.pop();
    //             if(dp[top.first] != -1){
    //                 string s = top.second
    //                 ans = max(ans , dp[top.first]+findMaxi(top.second));
    //                 continue;
    //             }
    //             if(g[top.first].size() == 0){
    //                 ans = max(ans , findMaxi(top.second));
    //             }else{
    //                 for(auto it: g[top.first]){
    //                     q.push({it , top.second+colors[it]});
    //                 }
    //             }
    //         }
    //     }
    //     return dp[node] = ;
    // }
    // bool isCycle(vector<int> g[],int n){
    //     int indegree[n];
    //     memset(indegree , -1 , sizeof(indegree));
    //     for(int i=0;i<n;i++){
    //         for(auto it: g[i]){
    //             indegree[it]++;
    //         }
    //     }
    //     queue<int> q;
    //     for(int i=0;i<n;i++){
    //         if(indegree[i] == 0){
    //             q.push(i);
    //         }
    //     }
    //     vector<int> temp;
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         temp.push_back(node);
    //         for(auto it: g[node]){
    //             indegree[it]--;
    //             if(indegree[it] == 0){
    //                 q.push(it);
    //             }
    //         }
    //     }
    //     return n == temp.size();
    // }
    // int largestPathValue(string colors, vector<vector<int>>& edges) {
    //     int n = colors.length();
    //     vector<int> g[n];
    //     for(auto it: edges){
    //         g[it[0]].push_back(it[1]);
    //     }
    //     if(isCycle(g , n)){
    //         return -1;
    //     }
    //     int ans = 0;
    //     vector<string> dp(n , '');
    //     for(int i=0;i<n;i++){
    //         if(dp[i] == ''){
    //             ans = max(ans , solve(i , g , colors , dp));
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    typedef array<int, 26> T;
public:
    int largestPathValue(string C, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(C.size());
        for (auto &e : E) {
            G[e[0]].push_back(e[1]); // build graph
            indegree[e[1]]++; // count indegrees
        }
        vector<T> cnt(C.size(), T{}); // cnt[i][j] is the maximum count of j-th color from the ancester nodes to node i.
        queue<int> q;
        for (int i = 0; i < C.size(); ++i) {
            if (indegree[i] == 0) { // if this node has 0 indegree, we can use it as a source node
                q.push(i);
                cnt[i][C[i] - 'a'] = 1; // the count of the current color should be 1
            }
        }
        int ans = 0, seen = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            int val = *max_element(begin(cnt[u]), end(cnt[u])); // we use the maximum of all the maximum color counts as the color value.
            ans = max(ans, val);
            ++seen;
            for (int v : G[u]) {
                for (int i = 0; i < 26; ++i) {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == C[v] - 'a')); // try to use node `u` to update all the color counts of node `v`.
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen < C.size() ? -1 : ans;
    }
};