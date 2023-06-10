class Solution {
public:
    bool possible(long long mid , long long left , long long right , long long sum){
        long long leftsum = 0 , rightsum=0;
        if (left<mid) {
            leftsum = left*mid - (left* (left-1)/2);
        }else{
            leftsum = (mid* (mid+1)/2) + (left-mid);
        }
        if (right<mid) {
            rightsum = right*mid - (right* (right+1)/2);
        }else{
            rightsum = (mid* (mid-1)/2) + (right-mid+1);
        }
        return sum >= (leftsum+rightsum);
        
    }
    int maxValue(int n, int index, int maxSum) {
        int start = 1 , end = maxSum;
        int ans = 0;
        while(start <= end){
            int mid = (start+end)/2;
            if(possible(mid , index+1 , n-index-1 , maxSum)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};