class Solution {
public:
    int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(32, 0);
        for(auto it: nums){
            for(int i=0;i<32;i++){
                if((it&(1<<i))){
                    freq[i]++;
                }
            }
        }
        long long ans = 0;
        for(int j=0;j<k;j++){
            long long num = 0;
            for(int i=0;i<32;i++){
                if(freq[i] > 0){
                    freq[i]--;
                    num+=(1<<i);
                }
            }
            ans = (ans + num*1LL*num)%MOD;
        }
        return ans;
    }
};