class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto it: nums1){
            int flag=0,add=0;
            for(int i=0;i<nums2.size();i++){
                if(flag==1){
                    if(nums2[i] > it){
                        ans.push_back(nums2[i]);
                        add=1;
                        break;
                    }
                }
                if(it == nums2[i]){
                    flag=1;
                }
            }
            if(add == 0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};