class Solution {
public:
    bool check(vector<int>& piles , int h , long long k){
        int ans = 0;
        for(auto it: piles){
            if(it%k == 0){
                ans+=(it/k);
            }else{
                ans+=(it/k);
                ans++;
            }
        }
        if(ans<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = 0 , low = 1;
        long long ans;
        for(auto it: piles){
            high+=it;
        }
        while(low<=high){
            long long mid = (high+low)/2;
            if(check(piles , h , mid)){
                high = mid-1;
                ans=mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};