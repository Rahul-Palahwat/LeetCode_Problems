class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto it: nums1){
            ans.push_back(it);
        }
        for(auto it: nums2){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        double fi = 0.0;
        if(ans.size() % 2 == 0){
            int t = ans.size()/2;
            t--;
            fi+=ans[t];
            fi+=ans[t+1];
            return fi/2.0;
        }else{
            return ans[ans.size()/2]*1.0;
        }
    }
};