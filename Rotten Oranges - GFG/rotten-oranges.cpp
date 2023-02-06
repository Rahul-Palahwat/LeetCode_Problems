//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int n,m;
    int ans = 0;
    queue<vector<int>> q;
    void solve(vector<vector<int>>& grid , vector<vector<bool>>& vis){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i ,j ,0});
                }
            }
        }
        while(!q.empty()){
            int t = q.size();
            while(t--){
                auto t = q.front();
                int i = t[0] , j = t[1] , time = t[2];
                ans = max(ans , time);
                q.pop();
                if(vis[i][j]){
                    continue;
                }
                vis[i][j] = 1;
                if(i<n-1 && j<m){
                    if(grid[i+1][j] == 1){
                        q.push({i+1 , j , time+1});
                        grid[i+1][j] = 2;
                    }
                }
                if(i>0 && j<m){
                    if(grid[i-1][j] == 1){
                        q.push({i-1 , j , time+1});
                        grid[i-1][j] = 2;
                    }
                }
                if(i<n && j<m-1){
                    if(grid[i][j+1] == 1){
                        q.push({i , j+1 , time+1});
                        grid[i][j+1] = 2;
                    }
                }
                if(i<n && j>0){
                    if(grid[i][j-1] == 1){
                        q.push({i , j-1 , time+1});
                        grid[i][j-1] = 2;
                    }
                }
            }
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m, false));
        solve(grid , vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends