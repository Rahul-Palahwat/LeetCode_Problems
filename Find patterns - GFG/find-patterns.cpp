//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int ans = 0;
        vector<int> taken(S.length()+1,0);
        for(int i=0;i<S.length();i++){
            int k=0;
            if(S[i]==W[k] && taken[i] != 1){
            k++;
            taken[i]=1;
            if(k==W.length()){
                ans++;
                continue;
            }
            for(int j=i+1;j<S.length();j++){
                if(S[j] == W[k] && taken[j] != 1){
                    k++;
                    taken[j]=1;
                }
                if(k==W.length()){
                    ans++;
                    k=0;
                    break;
                }
            }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends