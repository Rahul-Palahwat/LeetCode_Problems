class Solution {
public:
    
    // using two pointers 
    bool backspaceCompare(string s, string t) {
        int j = 0 , k = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '#'){
                if(j>0)
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(k>0)
                k--;
            }else{
                t[k++] = t[i];
            }
        }
        // string s1 = s.substr(0 , j);
        // string s2 = t.substr(0,k);
        // cout<<s1<<" "<<s2<<endl;
        return s.substr(0 , j) == t.substr(0,k);
    }
};