//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int xm=0 , xp=0 , ym=0 , yp=0 , x=0 , y=0;
        for(auto it: s){
            if(it == 'L'){
                x--;
                xm = min(xm , x);
            }else if(it == 'R'){
                x++;
                xp = max(xp , x);
            }else if(it == 'D'){
                y--;
                ym = min(ym , y);
            }else{
                y++;
                yp = max(yp , y);
            }
        }
        if(m<=(xp+abs(xm)) || n<=(yp+abs(ym))){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends