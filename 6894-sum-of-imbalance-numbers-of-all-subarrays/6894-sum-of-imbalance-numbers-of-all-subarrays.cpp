class Solution {
public:
    
    // Brute force 
    // int sumImbalanceNumbers(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //     vector<vector<int>> subArray;
    //     for(int i=0;i<n;i++){
    //         vector<int> temp;
    //         temp.push_back(nums[i]);
    //         for(int j=i+1;j<n;j++){
    //             temp.push_back(nums[j]);
    //             subArray.push_back(temp);
    //         }
    //     }
    //     for(int i=0;i<subArray.size();i++){
    //         sort(subArray[i].begin() , subArray[i].end());   
    //     }
    //     for(auto it: subArray){
    //         int temp = 0;
    //         for(int i=1;i<it.size();i++){
    //             if(it[i]-it[i-1] > 1){
    //                 temp++;
    //             }
    //         }
    //         ans+=temp;
    //     }
    //     return ans;
    // }
    
    
    
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            set<int> st;
            st.insert(nums[i]);
            int cnt = 0;
            for(int j=i+1;j<n;j++){
                if(st.count(nums[j])==0){
                    st.insert(nums[j]);
                    cnt++;
                    if(st.count(nums[j]-1)){
                        cnt--;
                    }
                    if(st.count(nums[j]+1)){
                        cnt--;
                    }
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};