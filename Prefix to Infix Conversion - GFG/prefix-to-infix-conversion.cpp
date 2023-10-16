//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre) {
        // Write your code here
        reverse(pre.begin() , pre.end());
        stack<string> st;
        for(auto it: pre){
            if(it == '*' || it == '/' || it == '+' || it == '-'){
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string temp = "(";
                temp+=s1;
                temp+=it;
                temp+=s2;
                temp+=')';
                st.push(temp);
            }else{
                string temp = "";
                temp+=it;
                st.push(temp);
            }
        }
        string ans = "";
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends