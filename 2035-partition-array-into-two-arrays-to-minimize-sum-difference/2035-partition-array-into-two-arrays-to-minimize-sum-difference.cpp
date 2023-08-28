class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int ans = 0 , n = nums.size() , sum = 0 , res = 0;
        sum = accumulate(nums.begin() , nums.end() , 0);
        int N = n/2;
        vector<vector<int>> left(N+1) , right(N+1);
        for(int mask = 0;mask < (1<<N);mask++){
            int sz = 0 , l = 0 , r = 0;
            for(int i=0;i<N;i++){
                if(mask & (1<<i)){
                    sz++;
                    l+=nums[i];
                    r+=nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        
        for(int i=0;i<=N;i++){
            sort(right[i].begin() , right[i].end());
        }
        
        res = min(abs(sum - 2*left[N][0]) , abs(sum - 2*right[N][0]));
        
        for(int sz = 1;sz<N;sz++){
            for(auto &it: left[sz]){
                auto &v = right[N-sz];
                int find = (sum - 2*it)/2;
                auto itr = lower_bound(v.begin() , v.end() , find);
                if(itr != v.end()){
                    res = min(res , abs(sum - 2*(it+(*itr))));
                }
            }
        }
        return res;
    }
};