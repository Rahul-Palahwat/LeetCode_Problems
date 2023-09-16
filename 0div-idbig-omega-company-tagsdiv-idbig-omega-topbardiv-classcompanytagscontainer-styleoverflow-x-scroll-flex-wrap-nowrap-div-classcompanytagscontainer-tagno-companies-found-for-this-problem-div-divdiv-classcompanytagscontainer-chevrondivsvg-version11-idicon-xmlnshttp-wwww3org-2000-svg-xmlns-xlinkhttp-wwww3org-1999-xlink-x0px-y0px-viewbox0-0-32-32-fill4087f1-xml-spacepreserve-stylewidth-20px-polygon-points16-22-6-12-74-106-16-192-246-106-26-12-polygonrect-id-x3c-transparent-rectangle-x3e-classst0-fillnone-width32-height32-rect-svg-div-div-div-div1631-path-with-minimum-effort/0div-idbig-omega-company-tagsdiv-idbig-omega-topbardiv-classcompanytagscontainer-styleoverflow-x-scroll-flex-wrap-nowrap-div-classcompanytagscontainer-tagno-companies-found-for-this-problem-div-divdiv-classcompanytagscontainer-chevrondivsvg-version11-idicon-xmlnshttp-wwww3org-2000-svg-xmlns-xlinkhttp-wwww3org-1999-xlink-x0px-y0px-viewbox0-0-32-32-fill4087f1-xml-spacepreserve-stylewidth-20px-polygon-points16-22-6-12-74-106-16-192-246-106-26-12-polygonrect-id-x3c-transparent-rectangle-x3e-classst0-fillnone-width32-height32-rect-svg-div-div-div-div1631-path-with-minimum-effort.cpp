class Solution {
public:
    int ans = INT_MAX;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        priority_queue<pair<int, pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq;
        pq.push({0 , {0 , 0}});
        int ans  = INT_MAX;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int diff = top.first;
            int i = top.second.first;
            int j = top.second.second;
            // cout<<diff<<" diff "<<i<< ' '<<j<<endl;
            if(i == n-1 && j == m-1){
                ans = min(ans , diff);
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            if(i+1 < n && !vis[i+1][j]){
                int temp = max(diff , abs(heights[i][j] - heights[i+1][j]));
                pq.push({temp , {i+1 , j}});
            }
            if(j+1 < m && !vis[i][j+1]){
                int temp = max(diff , abs(heights[i][j] - heights[i][j+1]));
                pq.push({temp , {i , j+1}});
            }
            if(i-1 >= 0 && !vis[i-1][j]){
                int temp = max(diff , abs(heights[i][j] - heights[i-1][j]));
                pq.push({temp , {i-1 , j}});
            }
            if(j-1 >= 0 && !vis[i][j-1]){
                int temp = max(diff , abs(heights[i][j] - heights[i][j-1]));
                pq.push({temp , {i , j-1}});
            }
        }
        return ans;
    }
};