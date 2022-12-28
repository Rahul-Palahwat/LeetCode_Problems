class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxh;
        int ans = 0;
        for(auto it: piles){
            maxh.push(it);
            ans+=it;
        }
        while(k--){
            int t = maxh.top();
            // cout<<t<<endl;
            if(t%2 == 0){
                ans-=(t/2);
                t=t/2;
            }else{
                ans-=(t/2);
                t-=(t/2);
            }
            maxh.pop();
            // cout<<t<<"t"<<ans<<endl;
            maxh.push(t);
        }
        
        return ans;
    }
};