class Solution {
public:
    // int kthGrammar(int n, int k) {
    //     string s = "" , temp = "0";
    //     n--;
    //     while(n--){
    //         for(auto it: temp){
    //             if(it == '0'){
    //                 s+="01";
    //             }else{
    //                 s+="10";
    //             }
    //         }
    //         temp = s;
    //         s="";
    //     }
    //     char ans = temp[k-1];
    //     if(ans == '0'){
    //         return 0;
    //     }
    //     return 1;
    // }
    
    int kthGrammar(int N, int K) {
	if (N == 1) return 0;
	if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
	else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
    }
};