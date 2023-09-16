class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        int ans = 0;
        for(auto it: nums){
            if(st.count(it-1)){
                continue;
            }else{
                int cnt = 0;
                while(st.count(it++)){
                    cnt++;
                }
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};