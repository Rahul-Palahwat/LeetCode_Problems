//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void solve(vector<bool> vis, string &s , string temp){
        if(temp.size() == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                temp+=s[i];
                vis[i] = true;
                solve(vis , s , temp);
                temp.pop_back();
                vis[i] = false;
            }
        }
        return;
    }
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.size();
        vector<bool> vis(n , false);
        string temp="";
        solve(vis , S , temp);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends