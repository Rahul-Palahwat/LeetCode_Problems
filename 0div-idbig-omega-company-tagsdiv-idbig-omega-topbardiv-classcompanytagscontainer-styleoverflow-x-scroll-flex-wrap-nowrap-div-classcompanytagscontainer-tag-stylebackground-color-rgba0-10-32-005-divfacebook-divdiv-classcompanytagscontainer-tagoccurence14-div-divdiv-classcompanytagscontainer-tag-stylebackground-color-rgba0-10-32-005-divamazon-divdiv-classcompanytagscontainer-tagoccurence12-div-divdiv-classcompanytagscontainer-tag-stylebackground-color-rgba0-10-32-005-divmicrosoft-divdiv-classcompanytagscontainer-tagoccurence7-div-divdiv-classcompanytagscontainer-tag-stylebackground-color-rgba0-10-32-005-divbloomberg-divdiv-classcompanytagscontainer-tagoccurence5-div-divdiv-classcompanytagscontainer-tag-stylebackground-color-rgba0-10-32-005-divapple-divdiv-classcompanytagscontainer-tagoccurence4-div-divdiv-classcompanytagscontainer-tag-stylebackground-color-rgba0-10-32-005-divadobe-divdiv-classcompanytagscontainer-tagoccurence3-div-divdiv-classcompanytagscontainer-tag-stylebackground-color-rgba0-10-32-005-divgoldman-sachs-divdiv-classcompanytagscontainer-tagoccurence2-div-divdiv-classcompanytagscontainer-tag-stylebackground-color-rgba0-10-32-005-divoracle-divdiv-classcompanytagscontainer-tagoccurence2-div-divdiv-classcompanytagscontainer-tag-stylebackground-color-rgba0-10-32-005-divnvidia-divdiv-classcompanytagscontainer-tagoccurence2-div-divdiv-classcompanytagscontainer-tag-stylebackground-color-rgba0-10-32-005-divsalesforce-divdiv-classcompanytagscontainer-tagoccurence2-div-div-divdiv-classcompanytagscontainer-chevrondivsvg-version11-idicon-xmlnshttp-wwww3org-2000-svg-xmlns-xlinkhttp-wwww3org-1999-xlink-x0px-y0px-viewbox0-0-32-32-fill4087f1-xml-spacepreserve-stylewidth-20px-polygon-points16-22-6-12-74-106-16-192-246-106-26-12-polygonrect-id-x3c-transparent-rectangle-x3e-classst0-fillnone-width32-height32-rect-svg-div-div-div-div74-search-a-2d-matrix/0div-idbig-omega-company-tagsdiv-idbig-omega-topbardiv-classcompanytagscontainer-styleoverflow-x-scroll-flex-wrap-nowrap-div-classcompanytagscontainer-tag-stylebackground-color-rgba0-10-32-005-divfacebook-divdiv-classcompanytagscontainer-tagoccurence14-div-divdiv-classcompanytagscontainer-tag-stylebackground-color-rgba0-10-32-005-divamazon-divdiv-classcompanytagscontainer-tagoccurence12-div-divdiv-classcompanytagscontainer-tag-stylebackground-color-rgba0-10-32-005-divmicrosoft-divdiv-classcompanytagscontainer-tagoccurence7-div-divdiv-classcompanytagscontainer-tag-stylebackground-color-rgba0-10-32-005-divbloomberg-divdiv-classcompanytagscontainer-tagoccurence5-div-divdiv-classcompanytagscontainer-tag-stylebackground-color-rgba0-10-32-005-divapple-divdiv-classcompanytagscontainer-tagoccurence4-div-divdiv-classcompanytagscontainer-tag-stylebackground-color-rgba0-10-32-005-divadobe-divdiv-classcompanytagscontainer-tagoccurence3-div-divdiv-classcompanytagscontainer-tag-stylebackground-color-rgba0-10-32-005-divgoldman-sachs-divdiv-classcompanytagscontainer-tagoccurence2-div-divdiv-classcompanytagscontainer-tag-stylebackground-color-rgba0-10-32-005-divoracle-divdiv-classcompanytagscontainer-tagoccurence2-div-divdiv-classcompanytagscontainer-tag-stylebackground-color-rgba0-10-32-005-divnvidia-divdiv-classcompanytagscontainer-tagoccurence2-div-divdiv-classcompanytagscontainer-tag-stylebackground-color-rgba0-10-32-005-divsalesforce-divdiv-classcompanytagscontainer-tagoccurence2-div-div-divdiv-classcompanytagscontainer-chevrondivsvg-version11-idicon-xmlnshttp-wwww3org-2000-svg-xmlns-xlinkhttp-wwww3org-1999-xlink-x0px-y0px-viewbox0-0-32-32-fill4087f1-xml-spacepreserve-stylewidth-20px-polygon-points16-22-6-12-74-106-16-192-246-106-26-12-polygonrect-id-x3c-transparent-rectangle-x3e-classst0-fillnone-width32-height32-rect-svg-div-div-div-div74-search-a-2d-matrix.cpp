class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0 , end = n-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(target < matrix[mid][0]){
                end = mid-1;
            }else{
                if(target <= matrix[mid][m-1]){
                    int s=0, e = m-1;
                    while(s <= e){
                        int m = (s+e)/2;
                        if(matrix[mid][m] == target){
                            return true;
                        }else if(target > matrix[mid][m]){
                            s = m+1;
                        }else{
                            e = m-1;
                        }
                    }
                    return false;
                }
                start = mid+1;
            }
        }
        return false;
    }
};