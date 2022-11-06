class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K>1){
            sort(S.begin(),S.end());
            return S;
        }else{
            // int j=0;
            string s = S;
            for(int i=0;i<S.length();i++){
                rotate(S.begin(),S.begin()+1,S.end());
                if(s>S){
                    s=S;
                }
            }
            return s;
        }
    }
};