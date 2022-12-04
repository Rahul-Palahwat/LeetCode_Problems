class Solution {
public:
    // set<vector<int>> s;
    // void solve(vector<int> ip , vector<int> op){
    //     if(ip.size() == 0){
    //         sort(op.begin(),op.end());
    //         s.insert(op);
    //         return;
    //     }
    //     vector<int> op1 = op;
    //     vector<int> op2 = op;
    //     op2.push_back(ip[0]);
    //     ip.erase(ip.begin()+0);
    //     solve(ip,op1);
    //     solve(ip,op2);
    //     return;
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     solve( arr , temp);
    //     for(auto it: s){
    //         ans.push_back(it);
    //     }
    //     return ans;
    // }
    
    
    set<vector<int>> s;
    void solve(vector<int> arr, int index, vector<int> temp){
        if(index>= arr.size()){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        vector<int> t = temp;
        solve(arr,index+1,temp);
        t.push_back(arr[index]);
        solve(arr,index+1,t);
        t.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,0,temp);
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};