class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
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
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it: g[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};