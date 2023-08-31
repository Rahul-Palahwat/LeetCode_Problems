class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     int n = nums.size();
    //     map<int,int, greater<int>> mp;
    //     int i=0;
    //     while(i<k){
    //         mp[nums[i]]++;
    //         i++;
    //     }
    //     int j=0;
    //     int maxi = 0;
    //     maxi = (*mp.begin()).first;
    //     ans.push_back(maxi);
    //     while(i<n){
    //         mp[nums[i]]++;
    //         mp[nums[j]]--;
    //         if(mp[nums[j]] == 0){
    //             mp.erase(nums[j]);
    //         }
    //         maxi = (*mp.begin()).first;
    //         ans.push_back(maxi);
    //         i++;
    //         j++;
    //     }
    //     return ans;
    // }
    
    
    
    // Using dequeue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> dq;
        int i=0 , j = 0;
        while(i<k){
            while(!dq.empty() && nums[i] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            i++;
        }
        ans.push_back(dq.front());
        while(i<n){
            if(dq.front() == nums[j]){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            // while(!dq.empty() && dq.front() < dq.back()){
            //     dq.pop_front();
            // }
            ans.push_back(dq.front());
            i++;
            j++;
        }
        return ans;
    }
};