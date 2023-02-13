class Solution {
public:
    // using stl
    // int strStr(string h, string needle) {
    //     return h.find(needle);
    // }
    
    // using rolling hash
    // bool check(string needle , string h , int j){
    //     // cout<<j<<endl;
    //     for(int x=0;x<needle.length();x++){
    //         if(needle[x]!=h[x+j]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int strStr(string h, string needle) {
    //     if(h.length() < needle.length()){
    //         return -1;
    //     }
    //     int total = 0;
    //     for(auto it: needle){
    //         total+=(it-'a');
    //     }
    //     // cout<<total<<"first"<<endl;
    //     int i=0,j=0;
    //     for(i=0;i<needle.length();i++){
    //         total-=(h[i]-'a');
    //     }
    //     // cout<<total<<"first loop"<<endl;
    //     if(total == 0){
    //         if(check(needle , h ,j)){
    //             return j;
    //         }
    //     }
    //     while(i<h.length()){
    //         total-=(h[i]-'a');
    //         total+=(h[j]-'a');
    //         j++;
    //         i++;
    //         // cout<<total<<"total"<<endl;
    //         if(total == 0 && check(needle , h ,j)){
    //             return j;
    //         }
    //     }
    //     return -1;
    // }
    
    
    // Using KMP and PI array
    
    
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
                j ? j = pos[j - 1] : i++;
            }
        }
        return -1;
    }
};