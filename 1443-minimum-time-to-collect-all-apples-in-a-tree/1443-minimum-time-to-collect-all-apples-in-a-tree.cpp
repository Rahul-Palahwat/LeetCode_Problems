class Solution {
public:
    // int ans = 0;
    // void solve(vector<int> g[n], vector<bool> hasApple,int n){
    //     vector<bool> vis(n,false);
    //     queue<int> q;
    //     q.push(0);
    //     int t = 
    //     while(q.size()>0){
    //         int t=q.front();
    //         q.pop();
    //         vis[t]=true;
    //         for(auto it: g[t]){
    //             if(it == t || vis[it] == true){
    //                 continue;
    //             }
    //             q.push(it);
    //         }
    //     }
    // }
    // int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    //     vector<int> g[n];
    //     for(auto it: edges){
    //         g[it[0]].push_back(it[1]);
    //         g[it[1]].push_back(it[0]);
    //     }
    //     solve(g,hasApple,n);
    //     return ans;
    // }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       // creating adjacency list
        vector<vector<int>> a(n);
        for (auto& x : edges) {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }

        return dfs(-1, 0, a, hasApple);
    }

    int dfs(int prev, int curr, vector<vector<int>>& a, vector<bool>& hasApple) {
        int ans = 0;
        for (auto x : a[curr]) {
            if (x != prev) {
                int res = dfs(curr, x, a, hasApple);
                if (res > 0 || hasApple[x]) {
                    ans += (res + 2);
                }
            }
        }
        return ans;
    }
};