class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> g[n];
        for(auto it: flights){
            g[it[0]].push_back({it[1] , it[2]});
        }
        vector<int> dist(n , INT_MAX);
        queue<pair<int,int>> q;
        q.push({0 , src});
        dist[src] = 0;
        int stops=0;
        while(!q.empty() && stops<=k){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                int node = top.second;
                int currentPrice = top.first;
                for(auto it: g[node]){
                    int nd = it.first;
                    int price = it.second;
                    if(currentPrice+price < dist[nd]){
                        dist[nd] = currentPrice+price; 
                        q.push({dist[nd] , nd});
                    }
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};