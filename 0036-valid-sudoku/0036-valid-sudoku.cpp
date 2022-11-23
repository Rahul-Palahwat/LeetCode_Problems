class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_map<char , int> mp;
            for(int j=0;j<board[0].size();j++){
                mp[board[i][j]]++;
            }
            for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
            }
        }
        for(int j=0;j<board[0].size();j++){
            unordered_map<char , int> mp;
            for(int i=0;i<board.size();i++){
                mp[board[i][j]]++;
            }
            for(auto it: mp){
                if(it.second>1 && it.first!= '.'){
                    return false;
                }
            }
        }
        unordered_map<char,int> mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=0;i<3;i++){
            for(int j=3;j<6;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=0;i<3;i++){
            for(int j=6;j<9;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        
        for(int i=3;i<6;i++){
            for(int j=0;j<3;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=3;i<6;i++){
            for(int j=3;j<6;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=3;i<6;i++){
            for(int j=6;j<9;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        
        for(int i=6;i<9;i++){
            for(int j=0;j<3;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=6;i<9;i++){
            for(int j=3;j<6;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        for(int i=6;i<9;i++){
            for(int j=6;j<9;j++){
                mp[board[i][j]]++;
            }
        }
        for(auto it: mp){
                if(it.second>1 && it.first != '.'){
                    return false;
                }
        }
        mp.clear();
        
        return true;
    }
};