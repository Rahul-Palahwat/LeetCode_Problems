class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        for(auto it: nums){
            if(it==0){
                return 0;
            }
            if(it<0){
                cnt++;
            }
        }
        if(cnt % 2 == 0){
            return 1;
        }
        return -1;
    }
};