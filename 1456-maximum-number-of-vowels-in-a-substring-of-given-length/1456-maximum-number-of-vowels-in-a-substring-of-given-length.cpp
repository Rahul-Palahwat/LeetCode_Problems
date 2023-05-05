class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0 , maxi = 0;
        int i=0,j=0;
        for(;i<k;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                cnt++;
        }
        maxi = max(maxi , cnt);
        for(;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                cnt++;
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                cnt--;
            j++;
            maxi = max(maxi , cnt);
        }
        return maxi;
    }
};