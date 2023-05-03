//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool possible(string s , map<string,int>& mp){
            string temp = s;
            reverse(s.begin() , s.end());
            if(mp.find(s) != mp.end()){
                if(mp[s] == mp[temp])
                    return true;
                return false;
            }
            return false;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string , int> mp;
        int check = 0;
        for(auto it: arr){
            mp[it]+=1;
        }
        for(auto it: arr){
            if(!possible(it , mp))
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends