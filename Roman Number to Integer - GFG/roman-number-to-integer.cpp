//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    unordered_map<string , int> mp;
    int romanToDecimal(string &str) {
        // code here
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        int n = str.size();
        string temp = "";
        int ans = 0;
        for(int i=0;i<n;i++){
            temp+=str[i];
            if(i<n-1){
                i++;
                temp+=str[i];
                if(mp.find(temp) != mp.end()){
                    ans+=mp[temp];
                }else{
                    temp.pop_back();
                    i--;
                    ans+=mp[temp];
                }
                temp = "";
            }else{
               ans+=mp[temp]; 
               temp="";
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends