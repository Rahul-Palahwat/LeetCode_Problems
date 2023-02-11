class Solution {
public:
    vector<int> ans;
    void solve(int n, int dst , vector<pair<int,int>> g[]){
        queue<pair<int,int>> q;
        map<vector<int>,int> vis;
        if(dst==0){
            ans.push_back(0);
            return;
        }
        for(auto it: g[0]){
            q.push({it.first , it.second});
        }
        int dis=1;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                auto top = q.front();
                q.pop();
                int node = top.first;
                int color = top.second;
                if(node == dst){
                    ans.push_back(dis);
                    return;
                }
                for(auto it: g[node]){
                    if(vis.find({node , it.first , it.second}) != vis.end()){
                        continue;
                    }
                    
                    if(it.second != color){
                        vis[{node , it.first , it.second}]=1;
                        q.push({it.first , it.second});
                    }
                }
            }
            
            dis++;
        }
        ans.push_back(-1);
        return;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> g[n];
        for(auto it: redEdges){
            g[it[0]].push_back({it[1] , 0});
        }
        for(auto it: blueEdges){
            g[it[0]].push_back({it[1] , 1});
        }
        for(int i=0;i<n;i++){
            solve(n , i , g);
        }
        return ans;
    }
};