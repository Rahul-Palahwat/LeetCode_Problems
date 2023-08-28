class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int sz = n/2;
        // vector<int> left[sz+1] , right[sz+1];
        vector<vector<int>> left(sz+1) , right(sz+1);
        for(int mask = 0;mask < (1<<sz) ; mask++){
            int cnt = 0 , l = 0 , r = 0;
            for(int i=0;i<sz;i++){
                if(mask & (1<<i)){
                    cnt++;
                    l+=nums[i];
                    r+=nums[sz+i];
                }
            }
            left[cnt].push_back(l);
            right[cnt].push_back(r);
        }
        for(int i=0;i<=sz;i++){
            sort(right[i].begin() , right[i].end());
        }
        int ans = min(abs(sum - 2*left[sz][0]) , abs(sum - 2*right[sz][0]));
        for(int i=1;i<sz;i++){
            for(auto &it: left[i]){
                auto &temp = right[sz-i];
                int find = (sum - 2*it)/2;
                auto itr = lower_bound(temp.begin() , temp.end() , find);
                if(itr != temp.end()){
                    ans = min(ans , abs(sum - 2*(it+(*itr))));
                }
            }
        }
        return ans;
    }
};