class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size();
        sort(temp.begin() , temp.end());
        int start = 0 , end = n-1;
        while(start < n && nums[start] == temp[start]){
            start++;
        }
        if(start == n){
            return 0;
        }
        while(end > 0 && nums[end] == temp[end]){
            end--;
        }
        return end-start+1;
    }
};