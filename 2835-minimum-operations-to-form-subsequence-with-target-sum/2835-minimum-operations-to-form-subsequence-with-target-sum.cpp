class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        // long long sum = accumulate(nums.begin() , nums.end() , 0);
        for(auto it: nums){
            sum+=it;
        }
        if(target > sum){
            return -1;
        }
        if(sum == target){
            return 0;
        }
        int ans = 0;
        priority_queue<int> maxh;
        for(auto it: nums){
            maxh.push(it);
        }
        while(target > 0 && maxh.size() > 0){
            int prev = maxh.top();
            while(maxh.size() > 0 && target < maxh.top()){
                prev= maxh.top();
                sum-=prev;
                maxh.pop();
            }
            // cout<<maxh.top()<<" "<<target<<endl;
            if(target > sum){
                maxh.push(prev/2);
                maxh.push(prev/2);
                sum+=prev;
                ans++;
            }else{
                target-=maxh.top();
                sum-=maxh.top();
                maxh.pop();
            }
        }
        return ans;
    }
};