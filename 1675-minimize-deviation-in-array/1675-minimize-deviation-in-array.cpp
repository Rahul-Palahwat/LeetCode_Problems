class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxh;
        int mini = INT_MAX;
        for(auto it: nums){
            if(it%2 != 0){
                maxh.push(it*2);
                mini = min(mini , it*2);
            }else{
                maxh.push(it);
                mini = min(mini , it);
            } 
        }
        int ans = maxh.top() - mini;
        while(maxh.top() %2 == 0){
            int t = maxh.top();
            ans = min(ans , t-mini);
            t/=2;
            mini = min(mini , t);
            maxh.pop();
            maxh.push(t);
        }
        ans = min(ans , maxh.top() - mini);
        return ans;
    }
};