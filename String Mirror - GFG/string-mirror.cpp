//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int n = str.length();
        string ans ="";
        ans+=str[0];
        int i=1 , flag=0;
        while(flag==0 && str[i] < str[i-1]){
            ans+=str[i];
            flag=1;
            i++;
        }
        while(flag==1 && str[i] <= str[i-1]){
            ans+=str[i];
            flag=1;
            i++;
        }
        string temp = ans;
        reverse(ans.begin() , ans.end());
        return temp+ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends