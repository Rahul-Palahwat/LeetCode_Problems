class Solution {
public:
    int solve(long long ans){
        int c=0;
        while(ans>0){
            int ttt = ans&1;
            c+=ttt;
            ans/=2;
        }
        return c;
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<num2){
            return -1;
        }
        long long tttt , dd;
        for(long long i=0;i<=65;i++){
            dd=num1;
            dd-=num2*i;
            tttt=solve(dd);
            if(tttt<=i){
                if(i<=dd)
                    return i;
            }
        }
        return -1;
    }
    
};