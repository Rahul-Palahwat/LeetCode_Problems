class Solution {
public:
    // using stl
    // int strStr(string h, string needle) {
    //     return h.find(needle);
    // }
    
    // using rolling hash
    bool check(string needle , string h , int j){
        // cout<<j<<endl;
        for(int x=0;x<needle.length();x++){
            if(needle[x]!=h[x+j]){
                return false;
            }
        }
        return true;
    }
    int strStr(string h, string needle) {
        if(h.length() < needle.length()){
            return -1;
        }
        int total = 0;
        for(auto it: needle){
            total+=(it-'a');
        }
        // cout<<total<<"first"<<endl;
        int i=0,j=0;
        for(i=0;i<needle.length();i++){
            total-=(h[i]-'a');
        }
        // cout<<total<<"first loop"<<endl;
        if(total == 0){
            if(check(needle , h ,j)){
                return j;
            }
        }
        while(i<h.length()){
            total-=(h[i]-'a');
            total+=(h[j]-'a');
            j++;
            i++;
            // cout<<total<<"total"<<endl;
            if(total == 0 && check(needle , h ,j)){
                return j;
            }
        }
        return -1;
    }
};