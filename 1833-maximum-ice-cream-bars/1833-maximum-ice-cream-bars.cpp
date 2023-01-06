class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(),costs.end());
        int i=0;
        while(coins > 0 && i<costs.size()){
            if(costs[i] <= coins){
                ans++;
                coins-=costs[i];
                i++;
            }else{
                break;
            }
        }
        return ans;
    }
};