//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        vector<int> ans;
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());
        int n = A.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({A[i]+B[n-1] , n-1});
        }
        while(!pq.empty() && K--){
            auto top = pq.top();
            pq.pop();
            int val = top.first;
            int ind = top.second;
            ans.push_back(val);
            if(ind-1 >= 0){
                val = val - B[ind] +B[ind-1];
                pq.push({val , ind-1});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends