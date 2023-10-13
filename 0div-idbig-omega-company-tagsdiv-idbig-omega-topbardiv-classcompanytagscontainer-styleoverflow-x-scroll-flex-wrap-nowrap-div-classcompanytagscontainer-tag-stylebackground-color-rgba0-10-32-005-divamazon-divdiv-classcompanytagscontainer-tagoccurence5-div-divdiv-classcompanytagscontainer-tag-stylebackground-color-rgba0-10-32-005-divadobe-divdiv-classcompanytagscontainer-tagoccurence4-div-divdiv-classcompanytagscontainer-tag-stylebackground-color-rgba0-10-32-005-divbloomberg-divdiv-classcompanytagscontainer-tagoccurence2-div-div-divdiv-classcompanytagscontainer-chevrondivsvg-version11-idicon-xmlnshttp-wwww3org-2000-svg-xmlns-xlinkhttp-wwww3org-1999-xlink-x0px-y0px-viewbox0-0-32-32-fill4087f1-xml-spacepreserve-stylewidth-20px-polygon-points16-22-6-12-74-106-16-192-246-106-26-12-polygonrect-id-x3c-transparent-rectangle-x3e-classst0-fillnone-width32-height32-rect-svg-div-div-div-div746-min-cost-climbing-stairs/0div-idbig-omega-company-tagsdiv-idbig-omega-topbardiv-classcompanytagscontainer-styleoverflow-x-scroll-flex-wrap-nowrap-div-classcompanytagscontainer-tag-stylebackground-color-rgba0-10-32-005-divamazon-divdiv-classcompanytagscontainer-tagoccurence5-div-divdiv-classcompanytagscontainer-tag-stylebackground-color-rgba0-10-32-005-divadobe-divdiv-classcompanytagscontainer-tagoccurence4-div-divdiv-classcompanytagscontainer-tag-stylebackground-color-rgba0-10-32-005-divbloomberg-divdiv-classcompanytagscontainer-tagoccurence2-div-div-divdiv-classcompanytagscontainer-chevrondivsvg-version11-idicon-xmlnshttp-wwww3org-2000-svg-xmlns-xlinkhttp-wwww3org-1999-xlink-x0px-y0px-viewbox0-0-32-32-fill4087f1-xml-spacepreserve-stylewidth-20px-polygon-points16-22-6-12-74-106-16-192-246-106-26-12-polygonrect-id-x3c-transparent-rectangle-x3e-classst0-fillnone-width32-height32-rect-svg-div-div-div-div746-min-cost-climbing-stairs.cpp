class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1];
        int ans = min(first , second);
        int n = cost.size();
        for(int i=2;i<n;i++){
            ans = min(cost[i]+second , cost[i]+first);
            first = second;
            second = ans;
        }
        return min(first, second);
    }
};