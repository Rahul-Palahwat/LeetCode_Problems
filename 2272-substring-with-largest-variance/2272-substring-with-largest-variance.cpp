class Solution {
public:
    int kadane(vector<int>& v){
        int ans = INT_MIN;
        int sum = 0;
        bool flag=false;
        for(int i=0;i<v.size();i++){
            if(v[i] == -1){
                flag=true;
            }
            sum+=v[i];
            if(flag){
                ans = max(ans , sum);
            }
            if(sum < 0){
                sum = 0;
                flag=false;
            }
        }
        if(flag){
            return ans;
        }
        return 0;
    }
    int solve(char a , char b , string& s){
        vector<int> v(s.size(),0) , v2(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i] == a){
                v[i] = -1;
            }else if(s[i] == b){
                v[i] = 1;
            }
        }
        int first = kadane(v);
        reverse(v.begin() , v.end());
        int second = kadane(v);
        return max(first , second);
    }
    int largestVariance(string s) {
        int n = s.size(),ans = 0;
        unordered_set<char> st(s.begin() , s.end());
        for(auto it: st){
            for(auto i: st){
                ans = max(ans , solve(it , i , s));
            }
        }
        return ans;
    }
};