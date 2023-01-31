//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        int ans = 0;
        int check = 0;
        int last=0;
        for(int i=0;i<B.length();i++){
            int j=0,k=i;
            int flag=0;
            while(j<A.length() && k<B.length()){
                if(A[j] != B[k]){
                    if(check == 1){
                        // cout<<"hello "<<j<<" "<<k<<endl;
                        return -1;
                    }
                    flag=1;
                    break;
                }
                j++;
                k++;
            }
            if(flag==0){
                if(check == 0){
                    last = i;
                }
                i=k-1;
                check=1;
                ans++;
            }
        }
        int flag=0;
        for(int i=0;i<A.length();i++){
            if(A[i] != B[i]){
                flag=1;
            }
        }
        if(flag==0){
            return ans;
        }
        ans++;
        int i = A.length()-1;
        // cout<<last<<" last"<<endl;
        while(last--){
            // cout<<A[i]<<" "<<B[last]<<endl;
            if(A[i] != B[last]){
                return -1;
            }
            i--;
        }
        return ans==1? -1: ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends