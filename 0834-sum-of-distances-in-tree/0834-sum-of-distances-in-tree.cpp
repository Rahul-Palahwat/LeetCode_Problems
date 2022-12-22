class Solution {
public:
    // void solve(int node , vector<int> g[], vector<int> &dis , vector<bool> &vis){
    //     queue<int> q;
    //     q.push(node);
    //     dis[node] = 0;
    //     while(!q.empty()){
    //         int t = q.front();
    //         q.pop();
    //         vis[t] = true;
    //         for(auto it: g[t]){
    //             if(vis[it]==true){
    //                 continue;
    //             }
    //             q.push(it);
    //             dis[it] = dis[t]+1;
    //         }
    //     }
    //     return;
    // }
    // vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    //     vector<int> ans;
    //     vector<int> g[n];
    //     for(auto it: edges){
    //         g[it[0]].push_back(it[1]);
    //         g[it[1]].push_back(it[0]);
    //     }
    //     for(int i=0;i<n;i++){
    //         vector<int> dis(n,INT_MAX);
    //         vector<bool> vis(n,0);
    //         solve(i,g,dis,vis);
    //         int sum = 0;
    //         for(auto it: dis){
    //             sum+=it;
    //         }
    //         ans.push_back(sum);
    //     }
    //     return ans;
    // }
        vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }

    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};