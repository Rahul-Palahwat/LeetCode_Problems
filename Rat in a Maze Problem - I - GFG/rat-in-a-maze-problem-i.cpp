//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void solve(int i , int j , vector<vector<int>> &m, int n, string s, vector<vector<bool>> vis){
        if(i>=n || j>=n || i<0 || j<0){
            return;
        }
        if(m[i][j] == 0){
            return;
        }
        if(i == n-1 && j == n-1){
            ans.push_back(s);
            return;
        }
        if(vis[i][j]){
            return;
        }
        vis[i][j] = true;
        s+='D';
        solve(i+1 , j , m , n , s , vis);
        s.pop_back();
        s+='R';
        solve(i , j+1 , m , n ,s , vis);
        s.pop_back();
        s+='U';
        solve(i-1 , j , m , n ,s , vis);
        s.pop_back();
        s+='L';
        solve(i , j-1 , m , n ,s , vis);
        s.pop_back();
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s = "";
        vector<vector<bool>> vis(n , vector<bool> (n , false));
        solve(0 , 0 , m , n , s, vis);
        // for(auto it: ans){
        //     cout<<it<<" ans"<<endl;
        // }
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