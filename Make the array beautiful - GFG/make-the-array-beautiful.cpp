//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int> ans;
        int pos = 0  , neg = 0;
        for(auto it: arr){
            if(it>=0){
                pos++;
            }else{
                neg++;
            }
        }
        if(pos > neg){
            int cnt=0;
            for(auto it: arr){
                if(it>=0){
                    if(cnt >= 0){
                        ans.push_back(it);
                    }
                    cnt++;
                }else{
                    if(cnt > 0){
                        ans.pop_back();
                    }
                    cnt--;
                }
            }
        }else{
            int cnt=0;
            for(auto it: arr){
                if(it<0){
                    if(cnt >= 0){
                        ans.push_back(it);
                    }
                    cnt++;
                }else{
                    if(cnt > 0){
                        ans.pop_back();
                    }
                    cnt--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends