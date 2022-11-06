class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        prev.push_back(1);
        ans.push_back(prev);
        numRows--;
        int i=0;
        // cout<<numRows<<endl;x
        while(numRows>=1){
            vector<int> temp;
            if(i==0){
                temp.push_back(1);
                temp.push_back(1);
                ans.push_back(temp);
                i++;
                numRows--;
                continue;
            }
            temp.push_back(1);
            for(int j=0;j<ans[i].size()-1;j++){
                // cout<<ans[i][j]<<"ans"<<endl;
                temp.push_back(ans[i][j]+ans[i][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            i++;
            numRows--;
        }
        return ans;
    }
};