class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // my 1st solution
        // int i=0,j=0;
        // vector<int> ans;
        // while(i<m && j<n){
        //     if(nums1[i]>nums2[j]){
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }else{
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }
        // }
        // while(i<m){
        //     ans.push_back(nums1[i]);
        //     i++;
        // }
        // while(j<n){
        //     ans.push_back(nums2[j]);
        //     j++;
        // }
        // nums1 = ans;
        
        // Now 2nd time 
        int i = m-1;
        int j =n-1;
        int tar = n+m-1;
        
        while (j >=0){
            if (i>=0 && nums1[i] > nums2[j]){
                nums1[tar] = nums1[i];
                tar -=1;
                i -=1;
            }
            else{
                nums1[tar] = nums2[j];
                tar -=1;
                j -=1;
            }
        }
    }
};