//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post) {
        // Write your code here
        string ans = "";
        stack<string> st;
        for(auto it: post){
            if(it == '+' || it == '-' || it == '*' || it == '/'){
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string temp = "";
                temp+=it;
                temp+=s2;
                temp+=s1;
                st.push(temp);
            }else{
                string temp= "";
                temp+=it;
                st.push(temp);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends