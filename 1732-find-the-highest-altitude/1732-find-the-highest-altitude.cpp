class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0 , maxi = 0;
        for(auto it: gain){
            ans+=it;
            maxi = max(maxi , ans);
        }
        return maxi;
    }
};