class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        sum = abs(sum-goal);
        if(sum%limit == 0 ){
            return sum/limit;
        }else{
            return (sum/limit)+1;
        }
    }
};