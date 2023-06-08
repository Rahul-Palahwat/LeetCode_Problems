class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int startm=0;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            for(int j = startm;j<m;j++){
                if(grid[i][j] < 0){
                    ans+=m-j;
                    startm = j;
                    break;
                }
            }
        }
        return ans;
    }
};