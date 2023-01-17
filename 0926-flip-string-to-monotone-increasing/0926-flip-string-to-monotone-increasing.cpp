class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> prefix, suffix(n,0);
        int count = 0;
        int one=0,zero=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                count++;
                one++;
            }else{
                zero++;
            }
            prefix.push_back(count);
        }
        count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] =='0'){
                count++;
            }
            suffix[i]=count;
        }
        int ans = INT_MAX;
        for(int i=1;i<s.length()-1;i++){
            if(s[i] == '0'){
                int change = prefix[i-1]+suffix[i+1];
                change = min(change , prefix[i-1]+(one-prefix[i-1]));
                ans = min(ans , change);
            }else{
                int change = prefix[i-1]+suffix[i+1];
                change  = min(change , zero);
                ans = min(ans , change);
            }
        }
        return ans;
    }
};