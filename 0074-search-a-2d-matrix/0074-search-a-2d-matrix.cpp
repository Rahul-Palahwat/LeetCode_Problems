class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int start = 0,mid;
        int end = matrix.size();
        int prev_mid = -1;
        while(start<end){
            mid = (start+end)/2;
            if(mid == prev_mid){
                break;
            }
            prev_mid = mid;
            if(target > matrix[mid][0]){
                start = mid;
            }else if(target < matrix[mid][0]){
                end = mid;
            }else{
                return true;
            }
        }
        // cout<<mid<<"mid"<<endl;
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[mid][i] == target){
                return true;
            }
        }
        return false;
        
        // my first approach 
        // int search=0;
        // for(int i=0;i<matrix.size();i++){
        //     if(matrix[i][0] == target){
        //         return true;
        //     }
        //     if(matrix[i][0]>target){
        //         search = i-1;
        //         break;
        //     }else{
        //         search = i;
        //     }
        // }
        // if(search<0){
        //     return false;
        // }
        // // cout<<search<<endl;
        // for(int i=0;i<matrix[0].size();i++){
        //     if(matrix[search][i] == target){
        //         return true;
        //     }
        // }
        // return false;
    }
};