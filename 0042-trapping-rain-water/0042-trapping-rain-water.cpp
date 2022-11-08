class Solution {
public:
    int trap(vector<int>& height) {
        
        // Brute force time O(N^2)
        // int ans = 0;
        // for(int i=1;i<height.size()-1;i++){
        //     int f=i-1,l=i+1;
        //     int maxil=0,maxir=0;
        //     while(f>=0){
        //         maxil = max(maxil,height[f]);
        //         f--;
        //     }
        //     while(l<height.size()){
        //         maxir = max(maxir,height[l]);
        //         l++;
        //     }
        //     maxil = min(maxil,maxir);
        //     if(maxil > height[i]){
        //         ans+=(maxil-height[i]);
        //     }
        // }
        // return ans;
        
        
        
       // Better using prefix max time O(N) space O(N)
//         int ans=0;
//         vector<int> prefix;
//         vector<int> postfix(height.size(),0);
//         prefix.push_back(height[0]);
        
//         for(int i=1;i<height.size();i++){
//             prefix.push_back(max(prefix[i-1],height[i]));
//         }
//         postfix[height.size()-1] = height[height.size()-1];
//         for(int i=height.size()-2;i>=0;i--){
//             postfix[i] = max(postfix[i+1],height[i]);
//         }
//         for(int i=1;i<height.size()-1;i++){
//             int h = min(prefix[i],postfix[i]);
//             if(h>height[i]){
//                 ans+=(h-height[i]);
//             }
//         }
//         return ans;
        
        
        // Optimal approach using two pointer time O(N) space O(1)
        int l=0,r=height.size()-1;
        int leftm=0,rightm=0;
        int ans=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l]>=leftm){
                    leftm=height[l];
                }else{
                    ans+=(leftm-height[l]);
                }
                l++;
            }else{
                if(height[r]>=rightm){
                    rightm = height[r];
                }else{
                    ans+=(rightm-height[r]);
                }
                r--;
            }
        }
        return ans;
        
    }
};