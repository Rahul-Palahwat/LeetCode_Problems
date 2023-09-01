class Solution {
public:
    // vector<int> kmpProcess(string s){
    //     int n = s.size();
    //     vector<int> ans(n , 0);
    //     int i=1 , len = 0;
    //     while(i<n){
    //         if(s[i] == s[len]){
    //             len++;
    //             ans[i] = len;
    //             i++;
    //         }else{
    //             if(len > 0){
    //                 len--;
    //             }else{
    //                 ans[i] = len;
    //                 i++;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // pi table or LPS i.e longest prefix same as suffix 
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
    
    
    int strStr(string h, string needle) {
        int n = needle.length();
        
        vector<int> pos = kmpProcess(needle);
        
        for(auto it: pos){
            cout<<it<<" ";
        }
        cout<<endl;
        
        // here comes KMP after pi table 
        int m = h.length();
        for (int i = 0, j = 0; i < m;) {
            if (h[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && h[i] != needle[j]) {
                if(j == 0){
                    i++;
                }else{
                    j = pos[j-1];
                }
            }
        }
        return -1;
    }
};