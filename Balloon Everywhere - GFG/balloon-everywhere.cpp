//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char , int> mp;
        for(auto it: s){
            mp[it]++;
        }
        if(mp.find('b') == mp.end() || mp.find('a') == mp.end() || mp.find('l') == mp.end() || mp.find('o') == mp.end() || mp.find('n') == mp.end()){
            return 0;
        }
        
        int temp = INT_MAX;
        temp = min(temp , mp['b']);
        temp = min(temp , min(mp['a'] , min(mp['l']/2 , min(mp['o']/2 , mp['n']))));
        return temp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends