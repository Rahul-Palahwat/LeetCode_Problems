//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool check(vector<vector<int>> nums , int n, int index){
        for(int i=0;i<n;i++){
            if(nums[index][i] == 1){
                return false;
            }
        }
        return true;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int flag=-1;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(M[j][i] == 1){
                    count++;
                }
            }
            if(count+1 == n){
                if(check(M , n , i)){
                    return i;
                }
            }
        }
        return -1;
        // code here 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends