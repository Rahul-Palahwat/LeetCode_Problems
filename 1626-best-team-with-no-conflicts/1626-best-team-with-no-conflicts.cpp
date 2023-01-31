class Solution {
public:
    vector<pair<int,int>> vec;
    int ans = 0;
    // void solve(int index , int sum , int prev){
    //     if(index == vec.size()){
    //         ans = max(ans , sum);
    //         return;
    //     }
    //     if(vec[index].second >= prev){
    //         solve(index+1 , sum+vec[index].second , vec[index].second);
    //     }
    //     solve(index+1 , sum , prev);
    //     return;
    // }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        for(int i=0;i<ages.size();i++){
            vec.push_back({ages[i] , scores[i]});
        }
        sort(vec.begin(),vec.end());
        int dp[ages.size()];
        for(int i=0;i<ages.size();i++){
            dp[i] = vec[i].second;
            for(int j=0;j<i;j++){
                if(vec[j].second <= vec[i].second){
                    dp[i] = max(dp[i] , dp[j]+vec[i].second);
                }
            }
            ans = max(ans , dp[i]);
        }
        // solve(0 , 0 , 0);
        return ans;
    }
};