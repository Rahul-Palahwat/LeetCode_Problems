class Solution {
public:
    // this question will use the concept of histogram, i.e nge
    int findHistoArea(vector<int> nums){
        int n = nums.size();
        stack<int> st1,st2;
        int ans = 0;
        vector<int> leftSmaller(n) , rightSmaller(n);
        for(int i=0;i<n;i++){
            while(st1.size() > 0 && nums[st1.top()] >= nums[i]){
                st1.pop();
            }
            if(st1.size() > 0){
                leftSmaller[i] = st1.top()+1;
            }else{
                leftSmaller[i] = 0;
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(st2.size() > 0 && nums[st2.top()] >= nums[i]){
                st2.pop();
            }
            if(st2.size() > 0){
                rightSmaller[i] = st2.top();
            }else{
                rightSmaller[i] = n;
            }
            st2.push(i);
        }
        for(int i=0;i<n;i++){
            ans = max(ans , abs(leftSmaller[i] - rightSmaller[i])*nums[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix[0].size();
        vector<int> nums(n , 0);
        for(int i=0;i<n;i++){
            if(matrix[0][i] == '1'){
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
        }
        ans = max(ans , findHistoArea(nums));
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    nums[j] = 1+nums[j];
                }else{
                    nums[j] = 0;
                }
            }
            ans = max(ans , findHistoArea(nums));
        }
        return ans;
    }
};