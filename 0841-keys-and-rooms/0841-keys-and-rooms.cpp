class Solution {
public:
    void solve(vector<int> g[], vector<bool> &vis){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            vis[t]=1;
            for(auto it: g[t]){
                if(vis[it] == 0){
                    q.push(it);
                }
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> graph[n];
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            for(auto it : rooms[i]){
                graph[i].push_back(it);
            }
        }
        solve(graph,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};