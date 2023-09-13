//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    vector<int> convertString(string s){
        vector<int> ans;
        for(auto it: s){
            ans.push_back(it-'0');
        }
        return ans;
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    string N="";
	    for(int i=0;i<n;i++){
	        N+=to_string(num[i]);
	    }
	    int sz = N.size();
        vector<string> ans;
        int mid = sz/2;
        if(sz%2 == 0){
            mid-=1;
        }
        string temp = N.substr(0 , mid+1);
        // cout<<temp<<" "<<mid<<endl;
        string next = temp;
        if(next[mid] == '9'){
            int ind = mid;
            while(ind >= 0 && next[ind] == '9'){
                ind--;
            }
            if(ind >= 0){
                string ch = "";
                ch+=next[ind];
                int val = stoi(ch);
                val+=1;
                // cout<<val<<" val "<<endl;
                ch = to_string(val);
                next[ind] = ch[0];
                ind++;
                while(ind <= mid){
                    next[ind] = '0';
                    ind++;
                }
            }
        }else{
            string ch = "";
            ch+=next[mid];
            int val = stoi(ch);
            val++;
            ch = to_string(val);
            next[mid] = ch[0];
        }
        // string next = to_string(stoi(temp)+1);
        // cout<<next<<endl;
        if(sz % 2 == 0){
            string tt = temp;
            reverse(temp.begin() , temp.end());
            ans.push_back(tt+temp);
            if(temp.size() == next.size()){
                tt = next;
                reverse(next.begin() , next.end());
                ans.push_back(tt+next);
            }
        }else{
            mid = temp.size();
            int end = temp.size()-2;
            while(end >= 0){
                temp+=temp[end];
                end--;
            }
            ans.push_back(temp);
            if(mid == next.size()){
                end = next.size()-2;
                while(end >= 0){
                    next+=next[end];
                    end--;
                }
                ans.push_back(next);
            }
        }
        for(auto it: ans){
            // cout<<it<<endl;
            if(it > N){
                return convertString(it);
            }
        }
        long long tttt = pow(10 , sz)+1;
        string ttt = to_string(tttt);
        // cout<<ttt<<endl;
        return convertString(ttt);
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends