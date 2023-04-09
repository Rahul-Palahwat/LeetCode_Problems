class Solution {
public:
    
    
    // most difficult way , but not able to solve 
//     int findMaxi(string s){
//         int ans = 0;
//         unordered_map<char , int> mp;
//         for(auto it: s){
//             mp[it]++;
//         }
//         for(auto it: mp){
//             ans = max(ans , it.second);
//         }
//         return ans;
//     }
//     void solve(int node , vector<int> g[] , string colors, vector<string>& dp){
//         int ans = 0;
//         queue<pair<int,string>> q;
//         string s="";
//         s+=colors[node];
//         q.push({node , s});
//         while(!q.empty()){
//             int t = q.size();
//             while(t--){
//                 auto top = q.front();
//                 q.pop();
//                 if(dp[top.first] != ''){
//                     string s = top.second;
//                     s.pop_back();
                    
//                     dp[node]
//                     continue;
//                 }
//                 if(g[top.first].size() == 0){
//                     ans = max(ans , findMaxi(top.second));
//                 }else{
//                     for(auto it: g[top.first]){
//                         q.push({it , top.second+colors[it]});
//                     }
//                 }
//             }
//         }
//         return dp[node] = ;
//     }
//     bool isCycle(vector<int> g[],int n){
//         int indegree[n];
//         memset(indegree , -1 , sizeof(indegree));
//         for(int i=0;i<n;i++){
//             for(auto it: g[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(indegree[i] == 0){
//                 q.push(i);
//             }
//         }
//         vector<int> temp;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             temp.push_back(node);
//             for(auto it: g[node]){
//                 indegree[it]--;
//                 if(indegree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
//         return n == temp.size();
//     }
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//         int n = colors.length();
//         vector<int> g[n];
//         for(auto it: edges){
//             g[it[0]].push_back(it[1]);
//         }
//         if(isCycle(g , n)){
//             return -1;
//         }
//         int ans = 0;
//         vector<string> dp(n , '');
//         for(int i=0;i<n;i++){
//             if(dp[i] == ''){
//                 solve(i , g , colors , dp);
//                 // ans = max(ans , solve(i , g , colors , dp));
//             }
//         }
//         return ans;
//     }
    
    
    
    
    // optimized way
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> g[n];
        vector<int> indegree(n , 0);
        for(auto it: edges){
            g[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int res = 0, vis = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            res = max(res, ++count[top][colors[top] - 'a']);
            vis++;
            for(auto it: g[top]){
                for (int i = 0; i < 26; i++) {
                    count[it][i] = max(count[it][i], count[top][i]);
                }
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return vis == n ? res : -1;
    }
};