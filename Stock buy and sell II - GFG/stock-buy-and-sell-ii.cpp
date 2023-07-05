//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
//   Recursion + Memoization
    // int solve(int index , bool hasPrev , vector<int>& prices , vector<vector<int>> &dp){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][hasPrev] != -1){
    //         return dp[index][hasPrev];
    //     }
    //     int notTaken = solve(index+1 , hasPrev , prices , dp);
    //     if(!hasPrev){
    //         return dp[index][hasPrev] = max(-prices[index]+solve(index+1 , !hasPrev , prices , dp) , notTaken);
    //     }else{
    //         return dp[index][hasPrev] = max(prices[index]+solve(index+1 , !hasPrev , prices , dp) , notTaken);
    //     }
    // }
    // int stockBuyAndSell(int n, vector<int> &prices) {
    //     // code here
    //     vector<vector<int>> dp(n , vector<int>(2 , -1));
    //     return solve(0 , 0 , prices , dp);
    // }
    
    
    // Tabulation
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
        for(int index = n-1;index >= 0;index--){
            for(int hasPrev = 1;hasPrev >= 0;hasPrev--){
                int notTaken = dp[index+1][hasPrev];
                if(!hasPrev){
                    dp[index][hasPrev] = max(-prices[index]+dp[index+1][!hasPrev], notTaken);
                }else{
                    dp[index][hasPrev] = max(prices[index]+dp[index+1][!hasPrev] , notTaken);
                }
            }
        }
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends