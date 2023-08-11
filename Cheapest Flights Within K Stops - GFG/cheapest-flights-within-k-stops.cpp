//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> g[n];
        for(auto it: flights){
            g[it[0]].push_back({it[1] , it[2]});
        }
        vector<int> minPrice(n , INT_MAX);
        queue<pair<int,int>> q;
        q.push({src , 0});
        minPrice[src] = 0;
        int start = 0;
        while(!q.empty() && start <= K){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                int node = top.first;
                int price = top.second;
                for(auto it: g[node]){
                    int nextNode = it.first;
                    int nextPrice = it.second;
                    if(nextPrice+price < minPrice[nextNode]){
                        minPrice[nextNode] = nextPrice+price;
                        q.push({nextNode , minPrice[nextNode]});
                    }
                }
            }
            start++;
        }
        return minPrice[dst] == INT_MAX ? -1 : minPrice[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends