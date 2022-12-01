class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        for(int i=0;i<s.length()/2;i++){
            if(s[i] == 'a' || s[i] == 'A'){
                count++;
            }
            if(s[i] == 'e' || s[i] == 'E'){
                count++;
            }
            if(s[i] == 'i' || s[i] == 'I'){
                count++;
            }
            if(s[i] == 'o' || s[i] == 'O'){
                count++;
            }
            if(s[i] == 'u' || s[i] == 'U'){
                count++;
            }
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'A'){
                count--;
            }
            if(s[i] == 'e' || s[i] == 'E'){
                count--;
            }
            if(s[i] == 'i' || s[i] == 'I'){
                count--;
            }
            if(s[i] == 'o' || s[i] == 'O'){
                count--;
            }
            if(s[i] == 'u' || s[i] == 'U'){
                count--;
            }
        }
        if(count==0){
            return true;
        }
        return false;
    }
};