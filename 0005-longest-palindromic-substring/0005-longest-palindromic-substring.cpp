class Solution {
public:
    
    // string longestPalindrome(string s) {
    //     string ans="";
    //     int n = s.length();
    //     int start = 0 , end = 0, len=0;
    //     for(int i=0;i<n;i++){
    //         int temps = i-1 , tempe = i+1,flag=0;
    //         while(temps >= 0 && tempe < n){
    //             if(s[temps] == s[tempe]){
    //                 temps--;
    //                 tempe++;
    //             }else{
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         int templen = tempe - temps - 1;
    //         if(len < templen){
    //             len = templen;
    //             start = temps+1;
    //             end = tempe;
    //         }
    //         temps = i , tempe = i+1;
    //         while(temps >= 0 && tempe < n){
    //             if(s[temps] == s[tempe]){
    //                 temps--;
    //                 tempe++;
    //             }else{
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         templen = tempe - temps - 1;
    //         if(len < templen){
    //             len = templen;
    //             start = temps+1;
    //             end = tempe-1;
    //         }
    //     }
    //     ans = s.substr(start ,len);
    //     return ans;
    // }
    
    
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        int startAns , endAns , sz=0;
        for(int i=0;i<n;i++){
            
            // Condition for middle element 
            int start = i-1 , end = i+1;
            while(start >=0 && end < n && s[start] == s[end]){
                start--;
                end++;
            }
            int tempLen = end-start-1;
            if(tempLen > sz){
                startAns = start+1;
                endAns = end;
                sz = tempLen;
            }
            // condition for not middle element
            start = i , end = i+1;
            while(start >= 0 && end < n && s[start] == s[end]){
                start--;
                end++;
            }
            tempLen = end-start-1;
            if(tempLen > sz){
                sz = tempLen;
                startAns = start+1;
                endAns = end-1;
            }
        }
        ans = s.substr(startAns , sz);
        return ans;
    }
};