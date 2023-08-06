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
    
    
    
    
    
    
    // Me trying another time 
    // bool canFinish(int numCourses, vector<vector<int>>& pre) {
    //     vector<int> ans;
    //     vector<int> adj[numCourses];
    //     for(auto it: pre){
    //         adj[it[1]].push_back(it[0]);
    //     }
    //     queue<int> q;
    //     vector<int> indegree(numCourses , 0);
    //     for(int i=0;i<numCourses;i++){
    //         for(auto it: adj[i]){
    //             indegree[it]++;
    //         }
    //     }
    //     for(int i=0;i<numCourses;i++){
    //         if(indegree[i] == 0){
    //             q.push(i);
    //         }
    //     }
    //     while(!q.empty()){
    //         auto top = q.front();
    //         q.pop();
    //         ans.push_back(top);
    //         for(auto it: adj[top]){
    //             indegree[it]--;
    //             if(indegree[it] == 0){
    //                 q.push(it);
    //             }
    //         }
    //     }
    //     return ans.size() == numCourses;
    //  }
    
    
    
    
    
    
    
    // 06/08/2023 by toposort by kanh's algorithm
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> g[numCourses];
        for(auto it: pre){
            g[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses , 0);
        for(int i=0;i<numCourses;i++){
            for(auto it: g[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            ans++;
            for(auto it: g[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans == numCourses;
     }
};