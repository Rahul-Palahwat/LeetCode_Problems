class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.size() > 0){
                if(nums[i] >= nums[st.top()]){
                    st.push(i);
                }else{
                    int replacement = st.top();
                    while(st.size() > 0 && nums[st.top()] > nums[i]){
                        replacement = st.top();
                        st.pop();
                    }
                    // cout<<"Hello"<<nums[i]<<" "<<nums[replacement]<<endl;
                    int val = nums[i];
                    nums[i] = nums[replacement];
                    nums[replacement] = val;
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }else{
                st.push(i);
            }
        }
        sort(nums.begin() , nums.end());
        return;
    }
};