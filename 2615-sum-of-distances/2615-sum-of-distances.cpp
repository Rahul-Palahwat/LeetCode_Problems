class Solution {
public:
    
    
    // optimized way
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long > ans(n , 0);
        vector<bool> vis(n , false);
        for(auto it: mp){
            if(it.second.size() > 1){
                vector<int> temp = it.second;
                int sz = temp.size();
                vector<long long> pre(sz) , post(sz);
                long long sum = 0;
                for(int i=0;i<sz;i++){
                    sum+=temp[i];
                    pre[i] = sum;
                }
                sum = 0;
                for(int i=sz-1;i>=0;i--){
                    sum+=temp[i];
                    post[i] = sum;
                }
                for(int i=0;i<sz;i++){
                    sum = 0;
                    sum-=pre[i];
                    sum+=(temp[i]*1LL*(i+1));
                    if(i<sz-1){
                        sum+=post[i+1];
                        sum-=(temp[i]*1LL*(sz-i-1));
                    }
                    ans[temp[i]] = sum;
                }
            }
        }
        return ans;
    }
    
    
    // my first approach , can be case of TLE but submitted O(n^2)
    // vector<long long> distance(vector<int>& nums) {
    //     unordered_map<int,vector<int>> mp;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         mp[nums[i]].push_back(i);
    //     }
    //     vector<long long > ans(n , 0);
    //     vector<bool> vis(n , false);
    //     for(int j=0;j<n;j++){
    //         if(!vis[j]){
    //             if(mp[nums[j]].size() > 1){
    //                 vector<int> temp = mp[nums[j]];
    //                 int sz = mp[nums[j]].size();
    //                 vector<long long> pre(sz) , post(sz);
    //                 long long sum = 0;
    //                 for(int i=0;i<sz;i++){
    //                     sum+=temp[i];
    //                     pre[i] = sum;
    //                 }
    //                 sum = 0;
    //                 for(int i=sz-1;i>=0;i--){
    //                     sum+=temp[i];
    //                     post[i] = sum;
    //                 }
    //                 for(int i=0;i<sz;i++){
    //                     sum = 0;
    //                     sum-=pre[i];
    //                     sum+=(temp[i]*1LL*(i+1));
    //                     if(i<sz-1){
    //                         sum+=post[i+1];
    //                         sum-=(temp[i]*1LL*(sz-1-i));
    //                     }
    //                     vis[temp[i]] = true;
    //                     ans[temp[i]] = sum;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};