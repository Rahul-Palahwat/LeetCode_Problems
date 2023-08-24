//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct Meeting{
        int start;
        int end;
    };
    static bool cmp(struct Meeting m1 , struct Meeting m2){
        if(m1.end >= m2.end){
            return false;
        }
        return true;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        struct Meeting Meet[n];
        int ans = 1;
        for(int i=0;i<n;i++){
            Meet[i].start = s[i];
            Meet[i].end = e[i];
        }
        sort(Meet , Meet+n , cmp);
        int endT = Meet[0].end;
        for(int i=1;i<n;i++){
            if(Meet[i].start > endT){
                ans++;
                endT = Meet[i].end;
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