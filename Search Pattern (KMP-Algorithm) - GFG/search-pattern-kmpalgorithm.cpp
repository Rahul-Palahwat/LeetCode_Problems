//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<int> makeKMP(string &s){
        int n = s.size();
        vector<int> ans(n , 0);
        int len = 0;
        for(int i=1;i<n;){
            if(s[i] == s[len]){
                len++;
                ans[i] = len;
                i++;
            }else if(len){
                len = ans[len-1];
            }else{
                i++;
            }
        }
        return ans;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            // Calling function to make the pi table
            vector<int> pos = makeKMP(pat);
            vector<int> ans;
            int n = txt.size() , m = pat.size();
            int i = 0 , j = 0;
            while(i<n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                if(j == m){
                    ans.push_back(i - m+1);
                    j=pos[j-1];
                }
                if(i<n && txt[i] != pat[j]){
                    if(j){
                        j = pos[j-1];
                    }else{
                        i++;
                    }
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends