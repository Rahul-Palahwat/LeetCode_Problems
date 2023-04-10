class Solution {
public:
    
    // TLE at the end cases 
    // int ans = INT_MAX;
    // int solve(vector<vector<int>>& grid ,int i ,int j ,int n , int m , vector<vector<int>>& dp){
    //     if(i>=n || j>=m){
    //         return INT_MAX;
    //     }
    //     if((i==(n-1)) && (j == (m-1))){
    //         return 1;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int movex = grid[i][j];
    //     int movey = grid[i][j];
    //     int moves = INT_MAX;
    //     for(int x=1;x<=movex;x++){
    //         int tr = solve(grid , i+x , j , n , m , dp);
    //         if(tr != INT_MAX)
    //             moves = min(moves , 1+tr);
    //     }
    //     for(int y = 1;y<=movey;y++){
    //         int tr = solve(grid , i , j+y , n , m , dp);
    //         if(tr != INT_MAX)
    //             moves = min(moves , 1+tr);
    //     }
    //     return dp[i][j] = moves;
    // }
    // int minimumVisitedCells(vector<vector<int>>& grid) {
    //     int n = grid.size() , m = grid[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m,-1));
    //     int ans = solve(grid , 0 , 0 , n , m,dp);
    //     return ans==INT_MAX ? -1 :ans;
    // }
    
    
    
    
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        if(n==1 && m==1){
            return 1;
        }
        // Dijkstra Algorithm
        priority_queue<vector<int> , vector<vector<int>> , greater<>> pq;
        vector<vector<int>> dis(n , vector<int>(m , INT_MAX));
        pq.push({1,0,0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int i = top[1] , j = top[2] , d = top[0];
            int moves = grid[i][j];
            for(int k=i+1 ; k<=min(i+moves , n-1) ; k++){
                if(dis[k][j] > d+1){
                    dis[k][j] = d+1;
                    pq.push({d+1 , k , j});
                    if(k == n-1 && j == m-1)
                        return d+1;
                }
            }
            for(int k=j+1 ; k<=min(j+moves , m-1);k++){
                if(dis[i][k] > d+1){
                    dis[i][k] = d+1;
                    pq.push({d+1 , i , k});
                    if(i == n-1 && k == m-1)
                        return d+1;
                }
            }
        }
        return -1;
    }
};