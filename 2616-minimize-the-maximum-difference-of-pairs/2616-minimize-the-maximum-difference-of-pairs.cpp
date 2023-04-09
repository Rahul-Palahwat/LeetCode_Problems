class Solution {
public:
    bool check(vector<int>& nums , int mid , int p){
        int cnt = 0;
        for(int i=nums.size()-1;i>0;i--){
            if((nums[i] - nums[i-1]) <= mid){
                cnt++;
                i--;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int start = 0 , end = 1e9,ans = 0;
        while(start <= end){
            int mid = (start+end)/2;
            if(check(nums , mid , p)){
                
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};