//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int col = image[sr][sc];
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first , j = top.second;
            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }
            if(vis[i][j] ){
                continue;
            }
            if(image[i][j] != col){
                continue;
            }
            vis[i][j] = true;
            image[i][j] = newColor;
            q.push({i+1 , j});
            q.push({i-1 , j});
            q.push({i , j-1});
            q.push({i , j+1});
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends