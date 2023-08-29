class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for(int i=n-2;i>=0;i--){
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }
        for(int i=0;i<n;i++){
            int mod = shifts[i]+(s[i] - 'a');
            mod%=26;
            char ch = 'a'+mod;
            s[i] = ch;
        }
        return s;
    }
};