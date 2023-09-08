class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // Loop to insert numRows vector's in ans
        for(int i=0;i<numRows;i++){
            // Creating a temporary vector to store value for that row
            vector<int> temp;
            // Starting value to be 1
            temp.push_back(1);
            // Base case when there is no previous row
            if(i == 0){
                ans.push_back(temp);
                continue;
            }
            // Inserting data to temp from prev temp
            for(int j=0;j<ans[i-1].size()-1;j++){
                temp.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            // Ending value to be 1
            temp.push_back(1);
            // Inserting temp vector in ans
            ans.push_back(temp);
        }
        return ans;
    }
};