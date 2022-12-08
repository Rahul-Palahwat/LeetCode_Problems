//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int vis[6][6];
    void solve(vector<vector<int>> m,int n,int i,int j,vector<string> &ans, string s){
        if(i==n-1 && j== n-1 && m[i][j] != 0){
            ans.push_back(s);
            return;
        }
        if(i<0 || j<0){
            return;
        }
        if(i>=n || j>=n){
            return;
        }
        if(vis[i][j] == 1){
            return;
        }
        if(m[i][j] ==0){
            return;
        }
        vis[i][j]=1;
        s+='D';
        solve(m,n,i+1,j,ans,s);
        s.pop_back();
        s+='R';
        solve(m,n,i,j+1,ans,s);
        s.pop_back();
        s+='U';
        solve(m,n,i-1,j,ans,s);
        s.pop_back();
        s+='L';
        solve(m,n,i,j-1,ans,s);
        s.pop_back();
        vis[i][j] = -1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        memset(vis,-1,sizeof(vis));
        vector<string> ans;
        solve(m,n,0,0,ans,"");
        // sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends