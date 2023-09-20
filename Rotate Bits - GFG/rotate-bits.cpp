//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int convertToInt(string s){
        long long ans = 0;
        long long val = 1;
        for(int i=0;i<16;i++){
            if(s[i] == '1'){
                ans+=(val);
            }
            val*=2;
        }
        return (int)ans;
    }
  public:
        vector <int> rotate (int n, int d)
        {
            d%=16;
            string s="0000000000000000";
            int i = 0;
            while(n > 0){
                if(n&1){
                    s[i] = '1';
                }
                i++;
                n/=2;
            }
            string l = s;
            reverse(l.begin() , l.begin() + 16 - d);
            reverse(l.begin()+16-d , l.end());
            reverse(l.begin() , l.end());
            string r = s;
            reverse(r.begin() , r.begin()+d);
            reverse(r.begin()+d , r.end());
            reverse(r.begin() , r.end());
            // cout<<r<<endl;
            // cout<<l<<endl;
            int leftVal=convertToInt(l) , rightVal = convertToInt(r);
            vector<int> ans;
            ans.push_back(leftVal);
            ans.push_back(rightVal);
            return ans;
        }
        
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends