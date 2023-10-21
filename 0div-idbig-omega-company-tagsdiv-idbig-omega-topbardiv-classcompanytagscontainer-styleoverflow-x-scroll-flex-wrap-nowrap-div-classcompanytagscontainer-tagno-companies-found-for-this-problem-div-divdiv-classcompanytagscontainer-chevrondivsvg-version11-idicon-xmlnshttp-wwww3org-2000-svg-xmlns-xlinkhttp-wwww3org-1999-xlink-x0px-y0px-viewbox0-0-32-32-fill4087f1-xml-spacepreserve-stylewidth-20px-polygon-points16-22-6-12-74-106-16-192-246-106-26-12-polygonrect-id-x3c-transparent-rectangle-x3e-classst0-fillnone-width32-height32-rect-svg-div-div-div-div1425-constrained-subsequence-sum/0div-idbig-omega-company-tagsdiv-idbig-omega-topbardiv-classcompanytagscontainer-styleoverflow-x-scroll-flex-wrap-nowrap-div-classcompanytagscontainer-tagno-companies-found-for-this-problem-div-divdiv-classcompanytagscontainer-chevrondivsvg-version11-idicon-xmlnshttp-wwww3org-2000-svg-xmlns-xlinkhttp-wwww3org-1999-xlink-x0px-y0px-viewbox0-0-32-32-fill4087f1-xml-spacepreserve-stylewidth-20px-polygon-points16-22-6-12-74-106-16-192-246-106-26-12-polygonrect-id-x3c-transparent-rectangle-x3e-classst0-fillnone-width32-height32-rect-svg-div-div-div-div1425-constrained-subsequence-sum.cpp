class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0] , 0});
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            while(!pq.empty() && i - pq.top().second > k){
                ans = max(ans , pq.top().first);
                pq.pop();
            }
            int val = nums[i];
            if(!pq.empty()){
                val+=max(0 , pq.top().first);
            }
            pq.push({val , i});
            ans = max(ans , val);
        }
        return ans;
    }
};