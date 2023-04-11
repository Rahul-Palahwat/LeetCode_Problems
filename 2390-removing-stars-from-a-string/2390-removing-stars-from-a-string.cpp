class Solution {
public:
    // Bruteforce
    // string removeStars(string s) {
    //     string ans="";
    //     int n = s.length();
    //     for(int i=0;i<n;i++){
    //         if(s[i] == '*'){
    //             ans.pop_back();
    //         }else{
    //             ans+=s[i];
    //         }
    //     }
    //     return ans;
    // }
    
    // Now using two pointers
    string removeStars(string s) {
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '*'){
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};