class Solution {
public:
    string convertBit(int n){
        string ans(30,'0');
        int b = 29;
        while(n>0){
            if((n&1) == 1){
                ans[b] = '1';
            }
            b--;
            n>>=1;
        }
        return ans;
    }
    int minFlips(int a, int b, int c) {
        int ans = 0;
        string sa = convertBit(a);
        string sb = convertBit(b);
        string sc = convertBit(c);
        // cout<<sa<<endl;
        // cout<<sb<<endl;
        // cout<<sc<<endl;
        for(int i=29;i>=0;i--){
            if(sc[i] == '0'){
                if(sa[i] == '1') ans++;
                if(sb[i] == '1') ans++;
            }else{
                if(sa[i] == '0' && sb[i] == '0') ans++;
            }
        }
        return ans;
    }
};