class Solution {
public:
    void solve(vector<int> g[] , int node , vector<bool>& vis , set<int>& st){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(vis[top]){
                st.erase(top);
                continue;
            }
            vis[top] = true;
            for(auto it: g[top]){
                q.push(it);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        set<int> temp;
        vector<int> g[n];
        for(auto it: edges){
            g[it[0]].push_back(it[1]);
        }
        vector<bool> vis(n , false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp.insert(i);
                solve(g , i , vis , temp);
            }
        }
        for(auto it: temp){
            ans.push_back(it);
        }
        return ans;
    }
};