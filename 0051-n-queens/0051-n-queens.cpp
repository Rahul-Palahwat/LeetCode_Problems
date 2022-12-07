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
    
    
    
    // 2nd approach striver time complexity O(n^2)
    // int queen[10];
    // vector<vector<int>> ans;
    // bool check(int col,int row,int n){
    //     // this is to check same column 
    //     if(queen[col] != -1){
    //         // cout<<col<<"samehello"<<row<<endl;
    //         return false;
    //     }
    //     int tcol=col;
    //     int trow = row;
    //     // this is to check left upward diagonal 
    //     while(trow >=0 && tcol >=0){
    //         if(queen[tcol] == trow){
    //             // cout<<col<<"hello1"<<row<<endl;
    //             return false;
    //         }
    //         trow--;
    //         tcol--;
    //     }
    //     trow = row;
    //     tcol = col;
    //     // this is to check right upward diagonal 
    //     while(trow>=0 && tcol < n){
    //         // cout<<queen[tcol]<<" h "<<trow<<endl;
    //         if(queen[tcol] == trow){
    //             // cout<<col<<"hello2"<<row<<endl;
    //             return false;
    //         }
    //         trow--;
    //         tcol++;
    //     }
    //     return true;
    // }
    // void solve(int row,int col , vector<int> temp){
    //     if(row == col){
    //         if(temp.size() == col)
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<col;i++){
    //         if(check(i,row,col)){
    //             // cout<<"hello"<<endl;
    //             queen[i] = row;
    //             temp.push_back(i);
    //             cout<<temp.size()<<endl;
    //             solve(row+1,col,temp);
    //             // cout<<temp.size()<<endl;
    //             temp.pop_back();
    //             queen[i] = -1;
    //         }
    //     }
    //     return;
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> finalans;
    //     memset(queen,-1,sizeof(queen));
    //     vector<int> temp;
    //     solve(0,n,temp);
    //     // cout<<ans.size()<<endl;
    //     for(auto it:ans){
    //         vector<string> st;
    //         for(auto i: it){
    //             string s(n,'.');
    //             s[i]='Q';
    //             st.push_back(s);
    //         }
    //         finalans.push_back(st);
    //     }
    //     return finalans;
    // }
    
    
    // optimization best approach
    int queen[10];
    int rightupper[21];
    int leftupper[21];
    vector<vector<int>> ans;
    void solve(int label, int n,vector<int> temp){
        if(label == n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if((queen[i] == 0) && (rightupper[i+label] == 0) && (leftupper[n+label-i] == 0)){
                queen[i]=1;
                temp.push_back(i);
                rightupper[i+label]=1;
                leftupper[n+label-i]=1;
                solve(label+1,n,temp);
                temp.pop_back();
                rightupper[i+label]=0;
                leftupper[n+label-i]=0;
                queen[i]=0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(queen,0,sizeof(queen));
        memset(rightupper,0,sizeof(rightupper));
        memset(leftupper,0,sizeof(leftupper));
        vector<vector<string>> finalans;
        vector<int> temp;
        solve(0,n,temp);
        // cout<<ans.size()<<endl;
        for(auto it: ans){
            vector<string> st;
            for(auto i:it){
                string s(n,'.');
                s[i]='Q';
                st.push_back(s);
            }
            finalans.push_back(st);
        }
        return finalans;
    }
    
};