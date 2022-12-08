class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char c){
        board[row][col] = '.';
        for(int i=0;i<9;i++){
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
        }
        col = col - (col%3);
        row = row - (row%3);
        unordered_map<char,int> mp;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] != '.'){
                    mp[board[i][j]] = 1;
                }
            }
        }
        if(mp.find(c) != mp.end()){
            return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int row){
        for(int i=row;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int k=1;k<=9;k++){
                        string c = to_string(k);
                        if(check(board,i,j,c[0])){
                            board[i][j] = c[0];
                            if(!solve(board,i)){
                                board[i][j]='.';
                            }else{
                                return true;
                            }
                        }
                    }
                    return false;
                    
                }
                else if(i==8 && j==8){
                    return true;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool t = solve(board,0);
        return;
    }
};