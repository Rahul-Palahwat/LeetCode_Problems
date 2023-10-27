class Solution {
public:
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
    
    
    
    
//     string longestPalindrome(string s) {
//         int n = s.size();
//         string ans = "";
//         for(int i=0;i<n;i++){
            
//         }
//     }
};