class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int ans = 0,penalty = n;
        vector<int> pen;
        int p=0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'N'){
                p++;
            }
            pen.push_back(p);
        }
        vector<int> penb(n,0);
        p=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                p++;
            }
            penb[i]=p;
        }
        vector<int> s;
        for(int i=0;i<pen.size();i++){
            s.push_back(pen[i]+penb[i]);
        }
        int tp = INT_MAX;
        for(int i=0;i<s.size();i++){
            tp=min(tp,s[i]);
            cout<<s[i]<<" ";
        }
        for(int i=0;i<s.size();i++){
            if(tp==s[i]){
                if(customers[i] == 'Y')
                return i+1;
                else
                    return i;
            }
        }
        return ans;
    }
};