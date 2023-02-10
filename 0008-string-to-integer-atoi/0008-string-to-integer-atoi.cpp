class Solution {
public:
    long atoi(string s, int sign, int i, long result) {
        if(sign*result>=INT_MAX){
            return INT_MAX;
        }
        if(sign*result<=INT_MIN){
            return INT_MIN;
        }
        if(i>=s.size()|| s[i]<'0' || s[i]>'9'){
            return sign*result;
        }
        
       
        result=atoi(s,sign,i+1,(result*10+(s[i]-'0')));
        
        return result;
    }


    int myAtoi(string s) {
        
        int i = 0, n = s.size(), sign = 1;
        while (i < n && s[i] == ' '){
            ++i;
        }
        if (s[i] == '-')
            sign = -1, ++i;
        else if (s[i] == '+')
            ++i;
        
        return atoi(s, sign, i, 0);
    }
    // int myAtoi(string s) {
    //     string temp="";
    //     int flag=-1,neg=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]-'0' <= 9 && s[i]-'0'>=0){
    //             flag=i;
    //             for(int j = i;j<s.length();j++){
    //                 if(s[j]-'0' <= 9 && s[j]-'0'>=0){
    //                     temp+=s[j];
    //                 }else{
    //                     break;
    //                 }
    //             }
    //             break;
    //         }
    //     }
    //     if(flag-1 >= 0){
    //         if(s[flag-1] =='-'){
    //             neg=1;
    //         }
    //         else if(s[flag-1] == '+'){
    //         }else
    //         return 0;
    //     }
    //     // cout<<temp<<endl;
    //     long long ans = 0;
    //     for(int i=0;i<temp.length();i++){
    //         ans = ans*10+(temp[i]-'0');
    //     }
    //     return ans>=INT_MAX ? neg == 1 ? -1*INT_MAX-1: INT_MAX : neg == 1 ? -1*ans : ans;
    // }
};