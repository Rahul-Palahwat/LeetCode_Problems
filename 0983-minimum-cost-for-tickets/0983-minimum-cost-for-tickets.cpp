class Solution {
public:
    int ans = INT_MAX;
    vector<int> dp;
    int solve(int index , vector<int>& days , vector<int>& costs){
        if(index >= days.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int first = costs[0]+solve(index+1 , days , costs);
        int i = index;
        while(i<days.size() && days[i] < days[index]+7){
            i++;
        }
        int second , third;
        if(i == index)
            second =costs[1] + solve(i+1 , days ,costs);
        else{
            second =costs[1] + solve(i , days , costs);
        }
        
        i=index;
        while(i<days.size() && days[i] < days[index]+30){
            i++;
        }
        if(i == index)
            third =costs[2] + solve(i+1 , days ,costs);
        else{
            third =costs[2] + solve(i , days , costs);
        }
        return dp[index] = min(first , min(second , third));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n , -1);
        return solve(0 , days , costs);
        return ans;
    }
};