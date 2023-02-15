class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> dig;
        while(k>0){
            dig.push_back(k%10);
            k/=10;
        }
        reverse(num.begin() , num.end());
        int m = dig.size();
        int i=0,j=0,carry=0;
        vector<int> ans;
        while(i<n && j<m){
            int sum = num[i]+dig[j];
            sum+=carry;
            ans.push_back(sum%10);
            carry = sum/10;
            i++;
            j++;
        }
        while(i<n){
            int sum = num[i]+carry;
            ans.push_back(sum%10);
            carry = sum/10;
            i++;
        }
        while(j<m){
            int sum = dig[j]+carry;
            ans.push_back(sum%10);
            carry = sum/10;
            j++;
        }
        if(carry > 0){
            ans.push_back(carry);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};