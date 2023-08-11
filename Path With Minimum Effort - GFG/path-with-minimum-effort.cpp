//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>> minh;
        minh.push({0 , {0 , 0}});
        int ans = INT_MAX;
        while(!minh.empty()){
            auto top = minh.top();
            minh.pop();
            int diff = top.first;
            int i = top.second.first;
            int j = top.second.second;
            if(i == n-1 && j == m-1){
                ans = min(ans , diff);
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j] = true;
            if(i+1 < n && !vis[i+1][j]){
                int temp = max(diff , abs(heights[i+1][j] - heights[i][j]));
                minh.push({temp , {i+1 , j}});
            }
            if(i-1 >= 0 && !vis[i-1][j]){
                int temp = max(diff , abs(heights[i-1][j] - heights[i][j]));
                minh.push({temp , {i-1 , j}});
            }
            if(j+1 < m && !vis[i][j+1]){
                int temp = max(diff , abs(heights[i][j+1] - heights[i][j]));
                minh.push({temp , {i , j+1}});
            }
            if(j-1 >= 0 && !vis[i][j-1]){
                int temp = max(diff , abs(heights[i][j-1] - heights[i][j]));
                minh.push({temp , {i , j-1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends