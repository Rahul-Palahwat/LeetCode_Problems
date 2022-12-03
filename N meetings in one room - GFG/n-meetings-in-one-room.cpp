//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    public:
    struct Meeting{
        int start;
        int end;
        int position;
    };
    static bool comparator(struct Meeting m1, Meeting m2){
        if(m1.end < m2.end){
            return true;
        }else if(m1.end>m2.end){
            return false;
        }else if(m1.position<m2.position){
            return true;
        }else{
            return false;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct Meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].position = i+1;
        }
        sort(meet,meet+n,comparator);
        int st = meet[0].end;
        vector<int> ans;
        ans.push_back(meet[0].position);
        for(auto it: meet){
            if(it.start > st){
                ans.push_back(it.position);
                st = it.end;
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends