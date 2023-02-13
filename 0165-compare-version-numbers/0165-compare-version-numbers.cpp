class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> first , second;
        string temp="";
        for(int i=0;i<v1.length();i++){
            if(v1[i] == '.'){
                first.push_back(stoi(temp));
                temp="";
            }else{
                temp+=v1[i];
            }
        }
        if(temp.length()>0){
            first.push_back(stoi(temp));
            temp="";
        }
        for(int i=0;i<v2.length();i++){
            if(v2[i] == '.'){
                second.push_back(stoi(temp));
                temp="";
            }else{
                temp+=v2[i];
            }
        }
        if(temp.length()>0){
            second.push_back(stoi(temp));
            temp="";
        }
        int f = 0 , s = 0;
        int n = first.size(), m = second.size();
        while(f<n && s< m){
            if(first[f] > second[s]){
                return 1;
            }else if(first[f] < second[s]){
                return -1;
            }
            f++;
            s++;
        }
        if(f<n){
            while(f<n){
                if(first[f] > 0){
                    return 1;
                }
                f++;
            }
        }
        if(s<m){
            while(s<m){
                if(second[s] > 0){
                    return -1;
                }
                s++;
            }
        }
        return 0;
    }
};