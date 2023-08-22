class Solution {
public:
    bool isPossible(string s , int i , int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool ans = true;
        int start = 0 , end = s.size()-1;
        int cnt = 0;
        while(start<end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
                return isPossible(s , start+1 , end) || isPossible(s , start , end-1);
            }
        }
        return ans;
    }
};