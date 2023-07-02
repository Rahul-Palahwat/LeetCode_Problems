//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    string toBinary(int n){
        string ans = "";
        while(n>0){
            if(n&1){
                ans+='1';
            }else{
                ans+='0';
            }
            n>>=1;
        }
        return ans;
    }
    int setSetBit(int x, int y, int l, int r){
        // code here
        string bin = toBinary(y);
        int two = 1;
        int temp = 0;
        // cout<<bin<<endl;
        for(int i=0;i<min((int)bin.size(),r);i++){
            // cout<<i<<" "<<endl;
            if(i >= l-1){
                if(bin[i] == '1'){
                    
                    temp+=two;
                }
            }
            two<<=1;
        }
        // cout<<temp<<"temp"<<endl;
        return x|temp;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends