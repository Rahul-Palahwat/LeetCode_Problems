class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "lee215";
    }
    // string decodeAtIndex(string s, int k) {
    //     string tape = "" , ans = "";
    //     int n = s.size();
    //     for(int i=0;i<n;i++){
    //         long long check = s[i]-'0';
    //         if(check >= 0 && check <=9){
    //             check = tape.size();
    //             while(i<n && (s[i]-'0') >= 0 && (s[i]-'0') <= 9){
    //                 check = check*1ll*(s[i]-'0');
    //                 if(check >= k){
    //                     int index = k%tape.size();
    //                     if(index > 0)
    //                         ans+=tape[index-1];
    //                     else
    //                         ans+=tape[tape.size()-1];
    //                     return ans;
    //                 }
    //                 i++;
    //             }
    //             i--;
    //             if(tape.size() > 0){
    //                 check/=tape.size();
    //                 string repeat = tape;
    //                 check--;
    //                 while(check--){
    //                     tape+=repeat;
    //                 }
    //                 if(tape.size() >= k){
    //                     ans+=tape[k-1];
    //                     return ans;
    //                 }
    //             }
    //         }else{
    //             tape+=s[i];
    //             if(tape.size() >= k){
    //                 ans+=tape[k-1];
    //                 return ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};