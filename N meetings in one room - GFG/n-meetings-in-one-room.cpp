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
        int position;
    };
    static bool cmp(struct Meeting m1 , struct Meeting m2){
        if(m1.end < m2.end){
            return true;
        }
        else if(m1.end > m2.end){
            return false;
        }else if(m1.position < m2.position){
            return true;
        }else{
            return false;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct Meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].position = i;
        }
        sort(meet , meet+n , cmp);
        int ans = 1;
        int last = meet[0].end;
        for(int i=1;i<n;i++){
            if(meet[i].start > last){
                ans++;
                last = meet[i].end;
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