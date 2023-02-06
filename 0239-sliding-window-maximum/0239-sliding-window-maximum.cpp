class Solution {
public:
    
    // using map
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         map<int,int , greater<int>> mp;
//         int j=0,i=0;
//         for(i=0;i<k;i++){
//             mp[nums[i]]++;
//         }
        
//         ans.push_back(mp.begin()->first);
//         while(i<nums.size()){
//             mp[nums[i]]++;
//             mp[nums[j]]--;
//             if(mp[nums[j]] == 0){
//                 mp.erase(nums[j]);
//             }
//             ans.push_back(mp.begin()->first);
//             i++;
//             j++;
//         }
//         return ans;
//     }
    
    
    // using queue and dequeue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // to remove out of bound elements
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            // remove all elements which are smaller than nums[i]
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};