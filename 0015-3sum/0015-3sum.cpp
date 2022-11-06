class Solution {
public:
    
    // my first solution 
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> s;
//         sort(nums.begin(),nums.end());
//         // unordered_map<vector<int>,int> mp;
//         for(int i=0;i<nums.size()-2;i++){
//             int j=i+1,k=nums.size()-1;
//             if(nums[i] >0){
//                 break;
//             }
//             if(nums[i]==0 && nums[i+1]==0 && nums[i+2]==0){
//                 vector<int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[i+1]);
//                     temp.push_back(nums[i+2]);
//                     s.insert(temp);
//                 break;
//             }
//             while(j<k){
//                 if((nums[i]+nums[j]+nums[k]) > 0){
//                     k--;
//                 }else if((nums[i]+nums[j]+nums[k]) < 0){
//                     j++;
//                 }else{
//                     vector<int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[k]);
//                     s.insert(temp);
//                     // cout<<i<<"i"<<nums[i]<<j<<"j"<<nums[j]<<"k"<<k<<nums[k]<<endl;
//                     j++;
//                 }
//             }

//         }
//         for(auto it:s){
//                 ans.push_back(it);
//             }
//         return ans;
//     }
    
    
    
    
    
    
    // Doing it again 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0){
                break;
            }
            if(nums[i]==0){
                if(nums[i+1]==0 && nums[i+2]==0){
                    vector<int> temp;
                    temp.push_back(0);
                    temp.push_back(0);
                    temp.push_back(0);
                    ans.push_back(temp);
                }
                break;
            }
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k]) > 0){
                    k--;
                }else if((nums[i]+nums[j]+nums[k]) < 0){
                    j++;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    int val = nums[j];
                    while((j<k) && (nums[j]==val)){
                        j++;
                    }
                    k--;
                }
            }
            while((i<nums.size()) &&nums[i+1]==nums[i]){
                i++;
            }
        }
        return ans;
    }
};