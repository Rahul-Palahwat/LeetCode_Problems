class Solution {
public:
    // bool find132pattern(vector<int>& nums) {
    //     stack<int> st;
    //     int mini = INT_MAX;
    //     for(auto it: nums){
    //         if(st.size() > 1){
    //             if(it < st.top() && it > mini){
    //                 return true;
    //             }
    //         }
    //         mini = min(mini , it);
    //         while(st.size() > 0 && st.top() > it){
    //             st.pop();
    //         }
    //         st.push(it);
    //     }
    //     return false;
    // }
    
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};