//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfs(int i, int j , vector<vector<char>>& mat){
        int n = mat.size() , m = mat[0].size();
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(mat[i][j] == 'X'){
            return;
        }
        mat[i][j] = 'X';
        dfs(i-1 , j , mat);
        dfs(i+1 , j , mat);
        dfs(i , j+1 , mat);
        dfs(i , j-1 , mat);
        return;
    }
    bool possible(int i, int j , vector<vector<char>>& mat , vector<vector<bool>>&vis){
        int n = vis.size() , m = vis[0].size();
        if(i<0 || j<0 || i>=n || j>= m){
            return false;
        }
        if(vis[i][j]){
            return true;
        }
        if(mat[i][j] == 'X'){
            return true;
        }
        vis[i][j] = true;
        bool ans = possible(i+1 , j , mat , vis);
        ans &= possible(i-1 , j , mat , vis);
        ans &= possible(i , j+1 , mat , vis);
        ans &= possible(i , j-1 , mat , vis);
        return ans;
    }
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && vis[i][j] == false){
                    // cout<<i<<" "<<j<<endl;
                    if(possible(i , j , mat , vis)){
                        dfs(i , j , mat);
                    }
                }
            }
        }
        return mat;
    }
    
    
    
    

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends