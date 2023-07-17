//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "" , temp="";
		    int n = A.size(), index = 0;
		    vector<int> vis(26 , 0);
		    for(int i=0;i<n;i++){
		        if(vis[A[i]-'a'] != 0){
		            vis[A[i]-'a']+=1;
		            while(index < temp.size() && vis[temp[index]-'a'] > 1){
		                index++;
		            }
		            if(index == temp.size()){
		                ans+='#';
		            }else{
		                ans+=temp[index];
		            }
		        }else{
		            vis[A[i]-'a'] += 1;
		            temp+=A[i];
		            ans+=temp[index];
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends