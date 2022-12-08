class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xo=0;
        for(auto it: nums){
            xo^=it;
        }
        return xo;
    }
};