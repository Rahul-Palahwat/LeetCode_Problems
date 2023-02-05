class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && nums[i] >= st.top()){
                st.pop();
            }
            if(st.size() > 0){
                // cout<<st.size()<<" "<<st.top()<<endl;
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
        
    }
};