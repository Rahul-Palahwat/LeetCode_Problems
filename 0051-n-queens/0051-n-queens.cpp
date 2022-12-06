class Solution {
public:
    
    // correct submission 
    vector<vector<string>> ans;
    vector<vector<int>> val;
    int queen[10];
    // to check if we can place or not 
    bool check(int row , int col){
        for(int i=0;i<row;i++){
            int trow = i;
            int tcol = queen[i];
            // if placing in the same colm or in the diagonal
            if((tcol == col) || (abs(tcol-col) == abs(trow-row))){
                return false;
            }
        }
        return true;
    }
    void solve(int label , int col , vector<int> s){
        if(label == col){
            // this will insert an array of integers in each row where the queen is present
            val.push_back(s);
            return;
        }
        for(int i=0;i<col;i++){
            // if valid then we will push otherwise not possible 
            if(check(label,i)){
                queen[label] = i;
                s.push_back(i);
                solve(label+1,col,s);
                // remove that position if valid or not valid 
                s.pop_back();
                queen[label] = -1;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(queen,-1,sizeof(queen));
        vector<int> s;
        solve(0,n,s);
        
        for(auto it: val){
            vector<string> temp;
            for(int i = 0;i<it.size();i++){
                string s="";
                for(int j=0;j<n;j++){
                    
                    if(j==it[i]){
                        s.push_back('Q');
                    }else{
                        s.push_back('.');
                    }
                }
                
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};