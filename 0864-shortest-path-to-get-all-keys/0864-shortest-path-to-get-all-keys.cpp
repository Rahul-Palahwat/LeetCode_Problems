class Solution {
public:
    
    // int solve(int i , int j , vector<string>& grid , int bit){
    //     int n = grid.size(), m=grid[0].size();
    //     queue<vector<int>> q;
    //     int ans = 0;
    //     unordered_set<string> st;
    //     q.push({i,j,0});
    //     while(!q.empty()){
    //         int sz = q.size();
    //         while(sz--){
    //             auto top = q.front();
    //             q.pop();
    //             int x=top[0],y=top[1],mask = top[2];
    //             string t = to_string(x)+" "+to_string(y)+" "+to_string(mask);
    //             if(st.find(t) != st.end()){
    //                 continue;
    //             }
    //             st.insert(t);
    //             if(bit == mask){
    //                 return ans;
    //             }
    //             grid[x][y] = mask+104;
    //             // cout<<grid[x][y]<<" mask "<<mask<<endl;
    //             if(x+1 < n && grid[x+1][y] != '#'){
    //                 if(grid[x+1][y] == 'a' || grid[x+1][y] == 'b' || grid[x+1][y] == 'c' || grid[x+1][y] == 'd' || grid[x+1][y] == 'e' || grid[x+1][y] == 'f'){
    //                     int index = grid[x+1][y]-'a'+1;
    //                     int temp = mask;
    //                     temp|=(1<<index);
    //                     q.push({x+1 , y , temp});
    //                 }
    //                 else if(grid[x+1][y] == 'A' || grid[x+1][y] == 'B' || grid[x+1][y] == 'C' || grid[x+1][y] == 'D' || grid[x+1][y] == 'E' || grid[x+1][y] == 'F'){
    //                     int index = grid[x+1][y]-'A'+1;
    //                     int no = (1<<index);
    //                     if(no&mask){
    //                         q.push({x+1 , y , mask});
    //                     }
    //                 }else{
    //                     q.push({x+1 , y , mask});
    //                 }
    //             }
    //             if(x-1 >= 0 && grid[x-1][y] != '#'){
    //                 if(grid[x-1][y] == 'a' || grid[x-1][y] == 'b' || grid[x-1][y] == 'c' || grid[x-1][y] == 'd' || grid[x-1][y] == 'e' || grid[x-1][y] == 'f'){
    //                     int index = grid[x-1][y]-'a'+1;
    //                     int temp = mask;
    //                     temp|=(1<<index);
    //                     q.push({x-1 , y , temp});
    //                 }
    //                 else if(grid[x-1][y] == 'A' || grid[x-1][y] == 'B' || grid[x-1][y] == 'C' || grid[x-1][y] == 'D' || grid[x-1][y] == 'E' || grid[x-1][y] == 'F'){
    //                     int index = grid[x-1][y]-'A'+1;
    //                     int no = (1<<index);
    //                     if(no&mask){
    //                         q.push({x-1 , y , mask});
    //                     }
    //                 }else{
    //                     q.push({x-1 , y , mask});
    //                 }
    //             }
    //             if(y+1 < m && grid[x][y+1] != '#'){
    //                 if(grid[x][y+1] == 'a' || grid[x][y+1] == 'b' || grid[x][y+1] == 'c' || grid[x][y+1] == 'd' || grid[x][y+1] == 'e' || grid[x][y+1] == 'f'){
    //                     int index = grid[x][y+1]-'a'+1;
    //                     int temp = mask;
    //                     temp|=(1<<index);
    //                     q.push({x , y+1 , temp});
    //                 }
    //                 else if(grid[x][y+1] == 'A' || grid[x][y+1] == 'B' || grid[x][y+1] == 'C' || grid[x][y+1] == 'D' || grid[x][y+1] == 'E' || grid[x][y+1] == 'F'){
    //                     int index = grid[x][y+1]-'A'+1;
    //                     int no = (1<<index);
    //                     if(no&mask){
    //                         q.push({x , y+1 , mask});
    //                     }
    //                 }else{
    //                     q.push({x , y+1 , mask});
    //                 }
    //             }
    //             if(y-1 >= 0 && grid[x][y-1] != '#'){
    //                 if(grid[x][y-1] == 'a' || grid[x][y-1] == 'b' || grid[x][y-1] == 'c' || grid[x][y-1] == 'd' || grid[x][y-1] == 'e' || grid[x][y-1] == 'f'){
    //                     int index = grid[x][y-1]-'a'+1;
    //                     int temp = mask;
    //                     temp|=(1<<index);
    //                     q.push({x , y-1 , temp});
    //                 }
    //                 else if(grid[x][y-1] == 'A' || grid[x][y-1] == 'B' || grid[x][y-1] == 'C' || grid[x][y-1] == 'D' || grid[x][y-1] == 'E' || grid[x][y-1] == 'F'){
    //                     int index = grid[x][y-1]-'A'+1;
    //                     int no = (1<<index);
    //                     if(no&mask){
    //                         q.push({x , y-1 , mask});
    //                     }
    //                 }else{
    //                     q.push({x , y-1 , mask});
    //                 }
    //             }
    //         }
    //         ans++;
    //     }
    //     return -1;
    // }
    
    
    // vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    // int solve(int i , int j , vector<string>& grid , int bit){
    //     int n = grid.size() , m = grid[0].size();
    //     queue<vector<int>> q;
    //     q.push({i , j , 0});
    //     int ans = 0;
    //     unordered_set<string> vis;
    //     string t = to_string(i)+" "+to_string(j)+" "+to_string(0);
    //     vis.insert(t);
    //     while(!q.empty()){
    //         int sz = q.size();
    //         while(sz--){
    //             auto top = q.front();
    //             q.pop();
    //             int mask = top[2];
    //             if(mask == bit){
    //                 return ans;
    //             }
    //             int temp;
    //             for(auto it: dirs){
    //                 int x = top[0]+it[0];
    //                 int y = top[1]+it[1];
    //                 if(x>=0 && x<n && y>=0 && y<m){
    //                     char ch = grid[x][y];
    //                     if(ch == '#'){
    //                         continue;
    //                     }else if(ch >= 'a' && ch <= 'f'){
    //                         // temp = mask;
    //                         int index = ch-'a'+1;
    //                         mask|=(1<<index);
    //                     }else if(ch >='A' && ch <= 'F'){
    //                         int index = ch-'A'+1;
    //                         int noo = (1<<index);
    //                         if((mask & noo) == 0){
    //                             continue;
    //                         }
    //                     }
    //                     string tt = to_string(x)+" "+to_string(y)+" "+to_string(mask);
    //                     if(!vis.count(tt)){
    //                         vis.insert(tt);
    //                         q.push({x,y,mask});
    //                     }
    //                 }
    //             }
    //         }
    //         ans++;
    //     }
    //     return -1;
    // }
    // int shortestPathAllKeys(vector<string>& grid) {
    //     int n = grid.size() , m = grid[0].size(), x,y;
    //     int bitMask = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j] == '@'){
    //                 x=i;
    //                 y=j;
    //             }
    //             if(grid[i][j] == 'a' || grid[i][j] == 'b' || grid[i][j] == 'c' || grid[i][j] == 'd' || grid[i][j] == 'e' || grid[i][j] == 'f'){
    //                 int index = grid[i][j]-'a'+1;
    //                 bitMask|=(1<<index);
    //             }
    //         }
    //     }
    //     // vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(bitMask+1 , -1)));
    //     return solve(x,y,grid,bitMask);
    // }
    
    
    
    
    int shortestPathAllKeys(vector<string>& grid) {
int x = -1, y = -1, m = grid.size(), n = grid[0].size(), max_len = -1;
for (int i = 0; i < m; ++i) {
for (int j = 0; j < n; ++j) {
char c = grid[i][j];
if (c == '@') {
x = i;
y = j;
}
if (c >= 'a' && c <= 'f') {
max_len = max(c - 'a' + 1, max_len);
}
}
}
vector<int> start = {0, x, y};
queue<vector<int>> q;
unordered_set<string> visited;
visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
q.push(start);
int step = 0;
vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
while (!q.empty()) {
int size = q.size();
for (int k = 0; k < size; ++k) {
vector<int> curr = q.front();
q.pop();
if (curr[0] == (1 << max_len) - 1)
return step;
for (auto &d : dirs) {
int i = curr[1] + d[0];
int j = curr[2] + d[1];
int keys = curr[0];
if (i >= 0 && i < m && j >= 0 && j < n) {
char c = grid[i][j];
if (c == '#') continue;
if (c >= 'a' && c <= 'f')
keys |= 1 << (c - 'a');
if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) {
continue;
}
if (!visited.count(to_string(keys) + " " + to_string(i) + " " + to_string(j))) {
visited.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
q.push({keys, i, j});
}
}
}
}
++step;
}
return -1;
}
};