class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> val(n,0);
        vector<int> g[n];
        for(auto it: roads){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({g[i].size(),i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int i=n;
        for(auto it: v){
            val[it.second] = i;
            ans+=(i*1LL*it.first);
            i--;
        }
        return ans;
    }
};