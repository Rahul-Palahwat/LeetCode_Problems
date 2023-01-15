class Solution {
public:
    
    
    int find(vector<int>& y,int i) {
		if(i==y[i]) return i;
		y[i]=find(y,y[i]);
		return y[i];
	}
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(),m=edges.size(),ans=0;
		vector<vector<int>> x(n);
		vector<int> y(n);
		for(int i=0;i<n;i++){
			y[i]=i;
			x[i]={vals[i],1};
		}
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
		for(int i=0;i<m;i++){
			int a=find(y,edges[i][0]);
			int b=find(y,edges[i][1]);
			if(x[a][0]!=x[b][0]){
				if(x[a][0]>x[b][0]) y[b]=a;
				else y[a]=b;
			}
			else{
				y[a]=b;
				ans+=x[a][1]*x[b][1];
				x[b][1]+=x[a][1];
			}
		}
		return ans+n;
	}
    
//     void solve(int index , vector<int> vals , vector<int> g[], int maxi , map<vector<int>,int>& ans){
//         stack<int> st;
//         vector<bool> vis(vals.size(),0);
//         st.push(index);
//         vector<int> temp;
//         while(st.size() > 0){
//             int n = 
//             int t=st.top();
//             st.pop();
//             if(vis[t] == true){
//                 continue;
//             }
//             vis[t] = true;
//             temp.push_back(t);
//             if(vals[t] == maxi){
//                 vector<int> ch=temp;
//                 reverse(ch.begin(),ch.end());
//                 if(ans.find(ch) == ans.end()){
//                     ans[temp]=1;
//                 }
//             }
//             if(vals[t] > maxi){
//                 temp.pop_back();
//                 continue;
//             }
//             if(g[t].size() == 1 && vis[g[t][0]]==true && vals[t] != maxi){
//                 temp.pop_back();
//                 continue;
//             }
//             for(auto it: g[t]){
//                 st.push(it);
//             }
//         }
//         return;
//     }
    
//     // void solve(int index , vector<int> vals , vector<int> g[], int maxi , map<vector<int>,int>& ans){
//     //     stack<int> st;
//     //     vector<bool> vis(vals.size(),0);
//     //     st.push(index);
//     //     vector<int> temp;
//     //     while(st.size() > 0){
//     //         int t=st.top();
//     //         st.pop();
//     //         if(vis[t] == true){
//     //             continue;
//     //         }
//     //         vis[t] = true;
//     //         temp.push_back(t);
//     //         if(vals[t] == maxi){
//     //             vector<int> ch=temp;
//     //             reverse(ch.begin(),ch.end());
//     //             if(ans.find(ch) == ans.end()){
//     //                 ans[temp]=1;
//     //             }
//     //         }
//     //         if(vals[t] > maxi){
//     //             temp.pop_back();
//     //             continue;
//     //         }
//     //         if(g[t].size() == 1 && vis[g[t][0]]==true && vals[t] != maxi){
//     //             temp.pop_back();
//     //             continue;
//     //         }
//     //         for(auto it: g[t]){
//     //             st.push(it);
//     //         }
//     //     }
//     //     return;
//     // }
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//         map<vector<int>,int> ans;
//         int n = vals.size();
//         vector<int> g[n];
//         for(auto it: edges){
//             g[it[0]].push_back(it[1]);
//             g[it[1]].push_back(it[0]);
//         }
//         for(int i=0;i<n;i++){
//             solve(i,vals,g,vals[i],ans);
//         }
//         for(auto it: ans){
//             for(auto i: it.first){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }
//         return ans.size();
//     }
};