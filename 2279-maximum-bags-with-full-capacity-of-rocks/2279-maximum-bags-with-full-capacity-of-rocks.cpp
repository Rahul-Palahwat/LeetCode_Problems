class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int> v;
        for(int i=0;i<rocks.size();i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(a - v[i] >= 0){
                ans++;
                a-=v[i];
            }else{
                break;
            }
        }
        return ans;
    }
};