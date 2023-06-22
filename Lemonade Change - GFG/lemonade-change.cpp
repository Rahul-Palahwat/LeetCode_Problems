//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bill) {
        // code here
        int cntf = 0 , cntt = 0;
        for(int i=0;i<N;i++){
            // cout<<bill[i]<<" ";
            if(bill[i] == 20){
                if((cntt > 0 && cntf > 0)){
                    cntt--;
                    cntf--;
                }else if(cntf >= 3){
                    cntf-=3;
                }else{
                    return false;
                }
            }else if(bill[i] == 10){
                if(cntf > 0){
                    cntf--;
                    cntt++;
                }else{
                    return false;
                }
            }else{
                cntf++;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends