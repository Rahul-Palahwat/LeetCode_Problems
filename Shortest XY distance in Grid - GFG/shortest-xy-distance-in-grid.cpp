//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//   int dis = INT_MAX;
//   int n,m;
//   void solve(int i , int j , vector<vector<char>> grid , vector<vector<bool>> vis){
//       queue<pair<int,int>> q;
//       n=grid.size();
//       m = grid[0].size();
//       q.push({i , j});
//       int d = 0;
//       while(!q.empty()){
//           int t = q.size();
//           if(d>dis){
//               return;
//           }
//         //   cout<<"Helo"<<t<<endl;
//           while(t--){
//               auto top = q.front();
//               int ii = top.first;
//               int jj = top.second;
//             //   cout<<ii<<" "<<jj<<endl;
//               q.pop();
//               if(vis[ii][jj]){
//                   continue;
//               }
//               vis[ii][jj] = true;
//               if(grid[ii][jj] == 'Y'){
//                 //   cout<<"Hello"<<d<<endl;
//                   dis = min(dis , d);
//                   return;
//               }
//               if((ii-1)>=0){
//                   q.push({ii-1 , jj});
//               }
//               if((jj-1) >=0){
//                   q.push({ii , jj-1});
//               }
//               if((ii+1)<n){
//                 //   cout<<"hello"<<endl;
//                   q.push({ii+1, jj});
//               }
//               if((jj+1)<m){
//                   q.push({ii , jj+1});
//               }
//           }
//           d++;
//       }
//   }
    // int shortestXYDist(vector<vector<char>> grid, int N, int M) {
    //     // code here
    //     vector<pair<int,int>> x;
    //     vector<vector<bool>> vis(N , vector<bool>(M,false));
    //     for(int i=0;i<N;i++){
    //         for(int j=0;j<M;j++){
    //             if(grid[i][j] == 'X'){
    //                 x.push_back({i,j});
    //             }
    //         }
    //     }
    //     int sz = x.size();
    //     for(int i=0;i<sz;i++){
    //         solve(x[i].first , x[i].second , grid , vis);
    //         if(dis==1){
    //             return dis;
    //         }
    //         // break;
    //     }
    //     return dis;
    // }
    
    
    // Brute force
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<pair<int,int>> x,y;
        int dis = INT_MAX;
        vector<vector<bool>> vis(N , vector<bool>(M,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j] == 'X'){
                    x.push_back({i,j});
                }
                if(grid[i][j] == 'Y'){
                    y.push_back({i , j});
                }
            }
        }
        int n = x.size() , m = y.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis = min(dis , abs(x[i].first-y[j].first)+abs(x[i].second - y[j].second));
                if(dis == 1){
                    return dis;
                }
            }
        }
        return dis;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends