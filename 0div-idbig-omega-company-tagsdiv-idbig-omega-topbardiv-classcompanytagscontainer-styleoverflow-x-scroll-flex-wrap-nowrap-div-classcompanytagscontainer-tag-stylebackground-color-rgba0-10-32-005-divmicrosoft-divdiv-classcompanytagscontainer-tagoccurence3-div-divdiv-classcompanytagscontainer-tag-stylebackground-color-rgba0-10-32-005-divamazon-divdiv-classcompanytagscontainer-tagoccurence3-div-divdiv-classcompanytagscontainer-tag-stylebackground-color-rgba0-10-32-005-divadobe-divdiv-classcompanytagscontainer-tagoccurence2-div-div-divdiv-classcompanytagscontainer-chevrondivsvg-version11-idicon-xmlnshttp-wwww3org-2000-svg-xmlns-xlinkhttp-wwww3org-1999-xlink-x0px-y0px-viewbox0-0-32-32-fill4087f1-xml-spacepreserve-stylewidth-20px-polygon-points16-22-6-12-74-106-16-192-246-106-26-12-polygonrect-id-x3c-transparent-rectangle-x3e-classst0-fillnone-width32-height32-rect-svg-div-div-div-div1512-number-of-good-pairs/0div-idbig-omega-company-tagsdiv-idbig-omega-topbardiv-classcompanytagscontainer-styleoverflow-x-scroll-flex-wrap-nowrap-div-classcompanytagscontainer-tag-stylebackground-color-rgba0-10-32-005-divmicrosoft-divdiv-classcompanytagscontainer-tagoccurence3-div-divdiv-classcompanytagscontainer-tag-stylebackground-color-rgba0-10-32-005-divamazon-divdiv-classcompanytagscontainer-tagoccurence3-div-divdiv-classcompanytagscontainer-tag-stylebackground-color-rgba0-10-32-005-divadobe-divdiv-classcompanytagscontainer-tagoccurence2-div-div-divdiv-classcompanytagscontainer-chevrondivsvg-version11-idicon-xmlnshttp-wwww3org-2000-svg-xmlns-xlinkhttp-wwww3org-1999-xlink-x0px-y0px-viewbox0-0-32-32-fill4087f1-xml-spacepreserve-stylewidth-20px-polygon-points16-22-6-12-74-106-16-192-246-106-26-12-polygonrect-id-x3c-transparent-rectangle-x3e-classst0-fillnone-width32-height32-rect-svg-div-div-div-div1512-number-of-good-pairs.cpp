class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(101 , 0);
        for(auto it: nums){
            v[it]++;
        }
        int ans = 0;
        for(int i=0;i<=100;i++){
            if(v[i] > 1){
                int temp = (v[i]*(v[i]-1))/2;
                ans+=temp;
            }
        }
        return ans;
    }
};