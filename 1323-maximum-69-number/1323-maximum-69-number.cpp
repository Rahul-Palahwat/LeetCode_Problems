class Solution {
public:
    int maximum69Number (int num) {
        vector<int> ans;
        while(num>0){
            ans.push_back(num%10);
            num/=10;
        }
        reverse(ans.begin(),ans.end());
        num=0;
        int flag=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==6 && flag==0){
                ans[i]=9;
                flag=1;
            }
            num = (num*10)+ans[i];
        }
        return num;
    }
};