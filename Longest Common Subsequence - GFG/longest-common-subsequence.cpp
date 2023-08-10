//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<int> dp(m+1 , 0);
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1 , 0);
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    temp[j] = 1+dp[j-1];
                }else{
                    temp[j] = max(temp[j-1] , dp[j]);
                }
            }
            dp = temp;
        }
        return dp[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends