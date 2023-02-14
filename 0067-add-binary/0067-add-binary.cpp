class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1;
        int m = b.length()-1;
        string ans = "";
        int carry = 0;
        while(n>=0 && m>=0){
            int temp = a[n]-'0';
            temp+=(b[m]-'0');
            temp+=carry;
            if(temp == 0){
                ans+='0';
                carry = 0;
            }else if(temp == 1){
                ans+='1';
                carry = 0;
            }else if(temp == 2){
                ans+='0';
                carry = 1;
            }else{
                ans+='1';
                carry = 1;
            }
            m--;
            n--;
        }
        while(m>=0){
            int temp = b[m]-'0';
            temp+=carry;
            if(temp == 0){
                ans+='0';
                carry = 0;
            }else if(temp == 1){
                ans+='1';
                carry = 0;
            }else if(temp == 2){
                ans+='0';
                carry = 1;
            }else{
                ans+='1';
                carry = 1;
            }
            m--;
        }
        while(n>=0){
            int temp = a[n]-'0';
            temp+=carry;
            if(temp == 0){
                ans+='0';
                carry = 0;
            }else if(temp == 1){
                ans+='1';
                carry = 0;
            }else if(temp == 2){
                ans+='0';
                carry = 1;
            }else{
                ans+='1';
                carry = 1;
            }
            n--;
        }
        if(carry == 1){
            ans+='1';
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};