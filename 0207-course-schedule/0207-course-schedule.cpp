class Solution {
public:
    
    // solve by topological sort using DAG(Directed Acyclic Graph) by Khan's algo
    // bool canFinish(int numCourses, vector<vector<int>>& pre) {
    //     vector<int> g[numCourses];
    //     for(auto it: pre){
    //         g[it[1]].push_back(it[0]);
    //     }
    //     vector<int> indegree(numCourses , 0);
    //     for(int i=0;i<numCourses;i++){
    //         for(auto it: g[i]){
    //             indegree[it]++;
    //         }
    //     }
    //     queue<int> q;
    //     int cnt = 0;
    //     for(int i=0;i<numCourses;i++){
    //         if(indegree[i] == 0){
    //             q.push(i);
    //         }
    //     }
    //     while(!q.empty()){
    //         auto top = q.front();
    //         q.pop();
    //         cnt++;
    //         for(auto it: g[top]){
    //             indegree[it]--;
    //             if(indegree[it] == 0){
    //                 q.push(it);
    //             }
    //         }
    //     }
    //     return cnt == numCourses;
    //  }
    
    
    
    // By DFS using topological sort
    // void dfs(int node , stack<int>& st , vector<bool>& vis , vector<int> adj[]){
    //     if(vis[node]){
    //         return;
    //     }
    //     vis[node] = true;
    //     for(auto it: adj[node]){
    //         dfs(it , st , vis , adj);
    //     }
    //     st.push(node);
    //     return;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& pre) {
    //     stack<int> st;
    //     vector<int> adj[numCourses];
    //     for(auto it: pre){
    //         adj[it[1]].push_back(it[0]);
    //     }
    //     vector<bool> vis(numCourses , false);
    //     for(int i=0;i<numCourses;i++){
    //         if(!vis[i]){
    //             dfs(i , st , vis , adj);
    //         }
    //     }
    //     vector<int> ans;
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         cout<<st.top()<<" ";
    //         st.pop();
    //     }
    //     cout<<endl;
    //     return ans.size() == numCourses;
    //  }
    
    
    
    
    
    
    // Me trying another time 
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<int> adj[numCourses];
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> indegree(numCourses , 0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it: adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans.size() == numCourses;
     }
};