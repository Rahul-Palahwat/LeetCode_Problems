class Solution {
public:
    unordered_map<int,int> dp;
    
    int solve(int n){
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        int ans = INT_MAX;
        if(n%2 == 0 && n%3 == 0){
            ans = min(ans , 1+solve(n/2));
            ans = min(ans , 1+solve(n/3));
        }else if(n%3 == 0){
            ans = min(ans , 1+solve(n/3));
            ans = min(ans , 1+solve(n-1));
        }else if(n%2 == 0){
            ans = min(ans , 1+solve(n/2));
            if((n-1)%3 == 0){
                ans = min(ans , 1+solve(n-1));
            }else{
                ans = min(ans , 2+solve(n-2));
            }
        }else{
            ans = min(ans , 1+solve(n-1));
            if((n-2) % 3 == 0){
                ans = min(ans , 2+solve(n-2));
            }
        }
        return dp[n] = ans;
    }
    int minDays(int n) {
        dp[0] = 0;
        return solve(n);
    }
};