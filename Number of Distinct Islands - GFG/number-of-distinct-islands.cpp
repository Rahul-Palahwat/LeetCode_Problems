//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<pair<int,int>>> total;
    void solve(int i , int j , vector<vector<int>>& grid , vector<vector<bool>>&vis){
        int n = grid.size() , m = grid[0].size();
        vector<pair<int,int>> temp;
        queue<pair<int,int>> q;
        q.push({i , j});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first , y = top.second;
            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            }
            if(grid[x][y] == 0){
                continue;
            }
            if(vis[x][y]){
                continue;
            }
            vis[x][y] = true;
            temp.push_back({x,y});
            q.push({x-1 , y});
            q.push({x+1 , y});
            q.push({x , y+1});
            q.push({x , y-1});
        }
        total.push_back(temp);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    solve(i , j , grid , vis);
                }
            }
        }
        set<vector<pair<int,int>>> st;
        for(int i=0;i<total.size();i++){
            int minix= INT_MAX , miniy=INT_MAX;
            for(auto it: total[i]){
                minix = min(minix , it.first);
                miniy = min(miniy , it.second);
            }
            for(int j=0;j<total[i].size();j++){
                total[i][j].first-=minix;
                total[i][j].second-=miniy;
            }
            sort(total[i].begin() , total[i].end());
            st.insert(total[i]);
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends