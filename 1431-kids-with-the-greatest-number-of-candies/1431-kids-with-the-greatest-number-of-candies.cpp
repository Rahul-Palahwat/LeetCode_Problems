class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(auto it: candies){
            maxi = max(maxi , it);
        }
        int n = candies.size();
        vector<bool> ans(n , false);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies >= maxi){
                ans[i] = true;
            }
        }
        return ans;
    }
};