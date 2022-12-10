//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it%k]++;
        }
        if(mp.find(0) != mp.end()){
            if(mp[0]%2 != 0){
                mp.erase(0);
                // cout<<"hello1"<<endl;
                return false;
            }
            mp.erase(0);
        }
        for(int i=1;i<=k/2;i++){
            if(mp.find(i) != mp.end()){
                if(mp.find(k-i) != mp.end()){
                    if(mp[i] != mp[k-i]){
                        // cout<<"hello2"<<endl;
                        return false;
                    }else{
                        mp.erase(i);
                        mp.erase(k-i);
                    }
                }else{
                    // cout<<"Hello3"<<endl;
                    return false;
                    
                }
            }
        }
        // cout<<mp.size();
        if(mp.size() == 0){
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends