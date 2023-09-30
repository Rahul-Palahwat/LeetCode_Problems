class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i] < maxi){
                return true;
            }
            while(st.size() > 0 && st.top() < nums[i]){
                maxi = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};