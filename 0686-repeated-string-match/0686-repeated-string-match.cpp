class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a.length() >= b.length()){
            if(a.find(b) == -1){
                a+=a;
                if(a.find(b) == -1){
                    return -1;
                }else{
                    return 2;
                }
            }
            return 1;
        }
        int ans = 0;
        int n = b.length();
        int start = b.find(a),end=0;
        // cout<<start<<"start"<<endl;
        if(start == -1){
            a+=a;
            if(a.find(b) != -1){
                return 2;
            }
            return -1;
        }
        int j=0;
        
        for(int i= start;i<n;i++){
            if(b[i] == a[j]){
                j++;
            }else{
                break;
            }
            if(j == a.length()){
                ans++;
                j=0;
                end = i;
            }
        }
        // cout<<ans<<" ans "<<start<<" start "<<end<<endl;
        if(start != 0){
            j = a.length()-1;
            for(int i = start-1;i>=0;i--){
                if(a[j] == b[i]){
                    
                }else{
                    // cout<<"hello"<<endl;
                    return -1;
                }
                j--;
            }
            ans++;
        }
        if(end < b.length()-1){
            j=0;
            for(int i=end+1;i<b.length();i++){
                if(a[j] != b[i]){
                    return -1;
                }
                j++;
            }
            ans++;
        }
        return ans;
    }
};