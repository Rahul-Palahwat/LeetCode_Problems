//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int,int> mp;
        for(auto it: hand){
            mp[it]++;
        }
        while(mp.size() > 0){
            int start = (mp.begin())->first, sz = 0;
            while(sz < groupSize){
                if(mp.find(start) == mp.end()){
                    return false;
                }
                mp[start]--;
                if(mp[start] == 0){
                    mp.erase(start);
                }
                start++;
                sz++;
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
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends