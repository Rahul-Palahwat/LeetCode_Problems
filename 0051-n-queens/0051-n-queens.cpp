class Solution {
public:
    
    // correct submission 
//     vector<vector<string>> ans;
//     vector<vector<int>> val;
//     int queen[10];
//     // to check if we can place or not 
//     bool check(int row , int col){
//         for(int i=0;i<row;i++){
//             int trow = i;
//             int tcol = queen[i];
//             // if placing in the same colm or in the diagonal
//             if((tcol == col) || (abs(tcol-col) == abs(trow-row))){
//                 return false;
//             }
//         }
//         return true;
//     }
//     void solve(int label , int col , vector<int> s){
//         if(label == col){
//             // this will insert an array of integers in each row where the queen is present
//             val.push_back(s);
//             return;
//         }
//         for(int i=0;i<col;i++){
//             // if valid then we will push otherwise not possible 
//             if(check(label,i)){
//                 queen[label] = i;
//                 s.push_back(i);
//                 solve(label+1,col,s);
//                 // remove that position if valid or not valid 
//                 s.pop_back();
//                 queen[label] = -1;
//             }
//         }
//         return;
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         memset(queen,-1,sizeof(queen));
//         vector<int> s;
//         solve(0,n,s);
        
//         for(auto it: val){
//             vector<string> temp;
//             for(int i = 0;i<it.size();i++){
//                 string s="";
//                 for(int j=0;j<n;j++){
                    
//                     if(j==it[i]){
//                         s.push_back('Q');
//                     }else{
//                         s.push_back('.');
//                     }
//                 }
                
//                 temp.push_back(s);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
    
    
    
    // 2nd approach striver 
    int queen[10];
    vector<vector<int>> ans;
    bool check(int col,int row,int n){
        if(queen[col] != -1){
            cout<<col<<"samehello"<<row<<endl;
            return false;
        }
        int tcol=col;
        int trow = row;
        while(trow >=0 && tcol >=0){
            if(queen[tcol] == trow){
                cout<<col<<"hello1"<<row<<endl;
                return false;
            }
            trow--;
            tcol--;
        }
        trow = row;
        tcol = col;
        while(trow>=0 && tcol < n){
            cout<<queen[tcol]<<" h "<<trow<<endl;
            if(queen[tcol] == trow){
                cout<<col<<"hello2"<<row<<endl;
                return false;
            }
            trow--;
            tcol++;
        }
        return true;
    }
    void solve(int row,int col , vector<int> temp){
        if(row == col){
            if(temp.size() == col)
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<col;i++){
            if(check(i,row,col)){
                // cout<<"hello"<<endl;
                queen[i] = row;
                temp.push_back(i);
                cout<<temp.size()<<endl;
                solve(row+1,col,temp);
                // cout<<temp.size()<<endl;
                temp.pop_back();
                queen[i] = -1;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> finalans;
        memset(queen,-1,sizeof(queen));
        vector<int> temp;
        solve(0,n,temp);
        // cout<<ans.size()<<endl;
        for(auto it:ans){
            vector<string> st;
            for(auto i: it){
                string s(n,'.');
                s[i]='Q';
                st.push_back(s);
            }
            finalans.push_back(st);
        }
        return finalans;
    }
    
};