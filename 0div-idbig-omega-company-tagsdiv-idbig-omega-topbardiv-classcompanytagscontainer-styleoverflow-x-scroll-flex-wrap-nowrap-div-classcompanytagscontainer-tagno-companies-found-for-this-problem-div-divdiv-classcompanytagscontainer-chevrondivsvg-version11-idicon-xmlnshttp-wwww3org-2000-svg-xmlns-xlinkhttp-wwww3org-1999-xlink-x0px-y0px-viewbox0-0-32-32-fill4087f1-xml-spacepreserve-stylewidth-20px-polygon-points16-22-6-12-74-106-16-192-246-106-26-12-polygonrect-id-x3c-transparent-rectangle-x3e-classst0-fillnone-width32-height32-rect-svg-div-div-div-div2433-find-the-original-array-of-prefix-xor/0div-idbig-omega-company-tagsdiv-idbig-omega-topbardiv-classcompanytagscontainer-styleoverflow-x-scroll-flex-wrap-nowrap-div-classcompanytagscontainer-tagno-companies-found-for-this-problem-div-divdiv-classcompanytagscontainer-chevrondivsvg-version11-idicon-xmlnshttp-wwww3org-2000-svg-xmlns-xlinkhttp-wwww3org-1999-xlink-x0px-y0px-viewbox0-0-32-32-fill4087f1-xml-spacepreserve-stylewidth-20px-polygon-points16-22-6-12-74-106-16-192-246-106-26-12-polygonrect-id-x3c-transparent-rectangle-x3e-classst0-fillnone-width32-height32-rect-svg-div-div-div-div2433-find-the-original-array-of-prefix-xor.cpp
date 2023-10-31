class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();i++){
            int temp = pref[i];
            vector<int> index;
            int k = 0;
            while(temp > 0){
                if(1 & temp){
                    index.push_back(k);
                }
                temp=temp>>1;
                k++;
            }
            
            // for(auto it : index){
            //     cout<<it<<" ";
            // }
            // cout<<i<<endl;
            
            temp = pref[i-1];
            for(int x=0;x<index.size();x++){
                temp = temp ^ (1<<index[x]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};