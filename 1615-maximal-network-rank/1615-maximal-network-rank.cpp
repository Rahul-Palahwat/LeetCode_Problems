class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int indegree[n];
        for(int i=0;i<n;i++){
            indegree[i] = 0;
        }
        map<pair<int,int> , int> mp;
        for(auto it: roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
            mp[{it[0] , it[1]}] =1;
            mp[{it[1] , it[0]}] = 1;
        }
        int ans = 0;
        for(auto it: roads){
            ans = max(ans , indegree[it[0]]+indegree[it[1]]-1);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find({i , j}) == mp.end()){
                    ans = max(ans , indegree[i]+indegree[j]);
                }
            }
        }
        return ans;
    }
};