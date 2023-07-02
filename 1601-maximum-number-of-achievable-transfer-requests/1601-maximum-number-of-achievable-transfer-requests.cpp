class Solution {
public:
    int solve(vector<vector<int>>& req , int index , vector<int> v , int cnt){
        if(index == req.size()){
            for(auto it: v){
                if(it != 0){
                    return 0;
                }
            }
            return cnt;
        }
        int notTaken = solve(req , index+1 , v , cnt);
        v[req[index][0]]--;
        v[req[index][1]]++;
        int taken = solve(req , index+1 , v , cnt+1);
        return max(taken , notTaken);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n , 0);
        return solve(requests , 0 , v , 0);
    }
};