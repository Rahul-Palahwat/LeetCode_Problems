//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<string> st;
        int ans = 0;
        for(auto it: S){
            if(it == '+' || it == '-' || it == '*' || it == '/'){
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                int val1 = stoi(s1) , val2 = stoi(s2);
                int val;
                if(it == '+'){
                    val = val2+val1;
                }else if(it == '-'){
                    val = val2-val1;
                }else if(it == '*'){
                    val = val2*val1;
                }else{
                    val = val2/val1;
                }
                // cout<<val<<" "<<endl;
                st.push(to_string(val));
            }else{
                string temp = "";
                temp+=it;
                st.push(temp);
            }
        }
        return stoi(st.top());
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends