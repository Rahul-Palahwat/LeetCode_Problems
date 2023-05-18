//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool solve(vector<vector<int>>& mat , int i , int j , int n , int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        if(mat[i][j] == 0){
            return true;
        }
        mat[i][j] = 0;
        bool ans = solve(mat , i+1 , j , n , m);
        ans&=solve(mat , i , j+1 , n , m);
        ans&=solve(mat , i-1 , j , n , m);
        ans&=solve(mat , i , j-1 , n , m);
        return ans;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j] == 1){
                    ans+=solve(matrix , i , j , N , M);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends