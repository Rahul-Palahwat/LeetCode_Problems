class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        priority_queue<int> maxh;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            maxh.push(prices[i]);
            ans = max(ans , maxh.top() - prices[i]);
        }
        return ans;
    }
};