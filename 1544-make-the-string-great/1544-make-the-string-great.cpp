class Solution {
public:
    string makeGood(string s) {
        for(int i=0;i<s.length()-1;i++){
            if((s[i]-97) == (s[i+1]-65) || (s[i]-65) == (s[i+1]-97)){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                if(i==0){
                    i-=1;
                }else{
                    i-=2;
                }
                if(s.length()==0){
                    break;
                }
                // i-=2;
                // if(i==-2){
                //     i=-1;
                // }
                // cout<<i<<"i"<<s<<endl;
            }
        }
        return s;
    }
};