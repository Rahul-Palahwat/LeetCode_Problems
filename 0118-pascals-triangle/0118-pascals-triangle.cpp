class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> temp;
        temp.push_back(1);
        v.push_back(temp);
        if(numRows == 1){
            return v;
        }
        temp.clear();
        temp.push_back(1);
        temp.push_back(1);
        v.push_back(temp);
        temp.clear();
        if(numRows == 2){
            return v;
        }
        for(int i=2;i<numRows;i++){
            temp.clear();
            for(int j=0;j<v[i-1].size();j++){
                // cout<<v[i-1].size()<<endl;
                if(j==0){
                    temp.push_back(1);
                }
                else if(j == v[i-1].size()-1){
                    temp.push_back(v[i-1][j-1]+1);
                    temp.push_back(1);
                }else{
                    // cout<<"hello";
                    temp.push_back(v[i-1][j] + v[i-1][j-1]);
                    // cout<<"hello";
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};