class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        map<int,int> mp1,mp2;
        set<int> st1 , st2;
        for(auto it: nums1){
            mp1[it] = 1;
        }
        for(auto it: nums2){
            mp2[it] = 1;
        }
        vector<int> temp;
        for(auto it: nums1){
            if(mp2.find(it) == mp2.end()){
                st1.insert(it);
            }
        }
        for(auto it: nums2){
            if(mp1.find(it) == mp1.end()){
                st2.insert(it);
            }
        }
        for(auto it: st1){
            temp.push_back(it);
        }
        ans.push_back(temp);
        temp.clear();
        for(auto it: st2){
            temp.push_back(it);
        }
        ans.push_back(temp);
        return ans;
    }
};