//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int ans = 0,flag1=0,flag2=0;
        while(A > max(C,D)){
            ans++;
            A/=2;
        }
        while(B > max(C,D)){
            ans++;
            B/=2;
        }
        if(C>D){
            if(A>B){
                while(B>D){
                    ans++;
                    B/=2;
                }
            }else{
                while(A>D){
                    ans++;
                    A/=2;
                }
            }
        }else{
            if(A>B){
                while(B>C){
                    ans++;
                    B/=2;
                }
            }else{
                while(A>C){
                    ans++;
                    A/=2;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends