//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> ans;
	    vector<int> g[N];
	    for(auto it: pre){
	        g[it.first].push_back(it.second);
	    }
	    vector<int> inDegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto it: g[i]){
	            inDegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(inDegree[i] == 0) q.push(i);
	    }
	    while(!q.empty()){
	        auto top = q.front();
	        q.pop();
	        ans.push_back(top);
	        for(auto it: g[top]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    if(ans.size() == N){
	        return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends