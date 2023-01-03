class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m = strs[0].length();
        int i=0,count=0;
        while(i<m){
            int t=0;
            for(int j=0;j<n-1;j++){
                // cout<<strs[j][i]<<" "<<strs[j+1][i]<<endl;
                if(strs[j][i] > strs[j+1][i]){
                    count++;
                    i++;
                    t=1;
                    break;
                }
            }
            if(t==0)
            i++;
        }
        return count;
    }
};