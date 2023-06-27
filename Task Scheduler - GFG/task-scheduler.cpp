//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        vector<int> v(26);
        for(auto it: tasks){
            v[it-'A']++;
        }
        sort(v.begin() , v.end() , greater<int>());
        int cnt = 1;
        for(int i=1;i<26;i++){
            if(v[i] == v[i-1]){
                cnt++;
            }else{
                break;
            }
        }
        return max(n , ((v[0]-1)*k) + v[0] + cnt-1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends