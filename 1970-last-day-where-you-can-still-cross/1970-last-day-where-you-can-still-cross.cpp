class Solution {
public:
    bool possible(int index , vector<vector<int>>&cells,int n, int m){
        vector<vector<int>> mat(n, vector<int>(m , 0));
        for(int i=0;i<=index;i++){
            mat[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(mat[0][i] == 0){
                q.push({0,i});
                mat[0][i] = 1;
            }
        }
        while(!q.empty()){
            auto top = q.front();
            if(top.first == n-1){
                return true;
            }
            q.pop();
            int x = top.first , y = top.second;
            if(x+1 < n && mat[x+1][y] == 0){
                q.push({x+1 , y});
                mat[x+1][y] = 1;
            }
            if(x-1 >= 0 && mat[x-1][y] == 0){
                q.push({x-1 , y});
                mat[x-1][y] = 1;
            }
            if(y+1 < m && mat[x][y+1] == 0){
                q.push({x , y+1});
                mat[x][y+1] = 1;
            }
            if(y-1 >= 0 && mat[x][y-1] == 0){
                q.push({x , y-1});
                mat[x][y-1] = 1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start = 0 , end = cells.size()-1;
        int ans = 0;
        vector<vector<int>> mat(row , vector<int>(col , 0));
        while(start<= end){
            int mid = (start+end)/2;
            if(possible(mid , cells , row , col)){
                ans = mid+1;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};