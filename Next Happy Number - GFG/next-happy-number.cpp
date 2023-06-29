//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check(int start){
        if(start == 1 || start == 7 || start == 10){
            return true;
        }
        if(start < 10){
            return false;
        }
        long long sum = 0;
        while(start > 0){
            int r = start%10;
            r*=r;
            sum+=r;
            start/=10;
        }
        return check(sum);
    }
    int nextHappy(int N){
        // code here
        int start = N+1;
        while(start){
            if(check(start)){
                return start;
            }
            start++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends