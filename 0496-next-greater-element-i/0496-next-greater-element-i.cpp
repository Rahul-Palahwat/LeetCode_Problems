class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        for(auto it: nums1){
            int flag=0;
            for(int i= mp[it] ;i< nums2.size();i++){
                if(nums2[i] > it){
                    ans.push_back(nums2[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};