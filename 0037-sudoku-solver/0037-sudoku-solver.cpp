class Solution {
public:
    
    bool isValid(char ch , int i , int j , vector<vector<char>> &board){
        for(int index=0;index<9;index++){
            if(board[i][index] == ch){
                return false;
            }
        }
        
        for(int index = 0 ; index < 9; index++){
            if(board[index][j] == ch){
                return false;
            }
        }
        int row = (i)/3;
        int col = (j)/3;
        for(int x = 3*row; x<3*(row+1); x++){
            for(int y = 3*col ; y < 3*(col+1) ; y++){
                if(board[x][y] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch = '1' ; ch <= '9' ; ch++){
                        if(isValid(ch , i , j , board)){
                            board[i][j] = ch;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};