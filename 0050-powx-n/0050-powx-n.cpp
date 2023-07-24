class Solution {
public:
    double solve(double x , long long n){
        if(n<=0){
            return 1.0;
        }
        double ans = solve(x , n/2);
        if(n%2 == 0){
            return ans*ans;
        }else{
            return ans*ans*x;
        }
    }
    double myPow(double x, int n) {
        int flag = 0;
        long long tt;
        if(n< 0){
            flag = 1;
        }
        if(n<0){
            tt = n*1LL*(-1);
        }else{
            tt = n;
        }
        cout<<tt<<endl;
        double ans = solve(x , tt);
        cout<<ans<<endl;
        if(flag == 1){
            return 1.0/ans;
        }
        return ans;
    }
};