class Solution {
public:
    int dij(int src , vector<pair<int,int>> g[] , int threshold , int n){
        vector<int> dis(n , 1e9);
        priority_queue<pair<int,int> , vector<pair<int , int>> , greater<pair<int,int>>> minh;
        minh.push({0 , src});
        dis[src] = 0;
        while(!minh.empty()){
            auto top = minh.top();
            minh.pop();
            int node = top.second;
            for(auto it: g[node]){
                int nextNode = it.first;
                int nextDis = it.second;
                if(nextDis + dis[node] < dis[nextNode]){
                    dis[nextNode] = nextDis+dis[node];
                    minh.push({dis[nextNode] , nextNode});
                }
            }
        }
        int cnt = 0;
        for(auto it: dis){
            if(it<=threshold){
                cnt++;
            }
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> g[n];
        for(auto it: edges){
            g[it[0]].push_back({it[1] , it[2]});
            g[it[1]].push_back({it[0] , it[2]});
        }
        int ans=-1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = dij(i , g , distanceThreshold , n);
            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};