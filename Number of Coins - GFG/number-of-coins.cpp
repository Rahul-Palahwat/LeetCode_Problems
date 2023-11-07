//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<int> dp;
	int solve(int coins[], int M, int V, int index){
	    if(V == 0){
	        return 0;
	    }
	    if(index >= M){
	        return 1e6;
	    }
	    if(dp[V] != -1){
	        return dp[V];
	    }
	    int ans = solve(coins, M, V, index+1);
	    if(V >= coins[index]){
	        ans = min(ans , 1+solve(coins, M, V-coins[index], index));
	    }
	    return dp[V] = ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins, coins+M);
	    dp.resize(V+1, -1);
	    int ans = solve(coins, M, V, 0);
	    if(ans >= 1e6){
	        return -1;
	    }
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends