class Solution {
    void findMini(int start, int end , vector<int>& nums, int x , long long temp,int &ans){
        int n = nums.size();
        while(start>=0){
            temp-=nums[start];
            start--;
            while(end >= 0 && temp < x){
                temp+=nums[end];
                end--;
            }
            // cout<<temp<<" "<<start<<" "<<end<<endl;
            if(temp == x){
                int cnt = start+1 + n-end-1;
                ans = min(ans , cnt);
            }
        }
        return;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0 , j = n-1;
        int ans = INT_MAX;
        long long temp = 0;
        while(i<n && temp < x){
            temp+=nums[i];
            i++;
        }
        if(i == n && temp < x){
            return -1;
        }else{
            if(temp == x){
                ans = min(ans , i);
            }
            // cout<<ans<<" ans"<<endl;
            i--;
            findMini(i , j , nums , x , temp, ans);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};