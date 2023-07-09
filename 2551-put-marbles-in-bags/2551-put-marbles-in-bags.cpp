class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = 0;
        vector<long long> v;
        int n = weights.size();
        for(int i=1;i<n;i++){
            v.push_back(weights[i]+weights[i-1]);
        }
        sort(v.begin() , v.end());
        long long first=0,second = 0;
        int sz = v.size();
        for(int i=0;i<min(k-1 , sz);i++){
            first+=v[i];
            second+=v[sz-i-1];
        }
        return second-first;
        // return first-second > 0 ? first-second: 0;
    }
};