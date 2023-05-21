class Solution {
public:
    
    // using bruteforce approach , i.e storing all points of both islands in two sets and will find the minimum between them
    void solve(int i , int j , vector<vector<int>>& grid , set<pair<int,int>>& st){
        int n = grid.size();
        if(i>=n || j>=n || i<0 || j<0){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        st.insert({i , j});
        solve(i+1 , j , grid , st);
        solve(i-1 , j , grid , st);
        solve(i , j+1 , grid , st);
        solve(i , j-1 , grid , st);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() , flag=0;
        set<pair<int,int>> st1 , st2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(flag==0){
                        solve(i,j,grid , st1);
                        
                        flag=1;
                    }else{
                        solve(i , j , grid , st2);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto it: st1){
            for(auto i: st2){
                ans = min(ans , abs(it.first-i.first)+abs(it.second - i.second)-1);
            }
        }
        return ans;
    }
};