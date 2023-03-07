class Solution {
public:
    bool check(vector<int>& time , int total , long long total_time){
        long long ans = 0;
        for(auto it: time){
            ans+=(total_time / it);
        }
        if(ans >= total){
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int total) {
        int n = time.size();
        long long high = total*1LL*time[n-1];
        long long low=0,ans;
        while(low<=high){
            long long mid = (high+low)/2;
            if(check(time , total , mid)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};