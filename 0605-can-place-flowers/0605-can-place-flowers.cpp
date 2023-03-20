class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if(sz == 1){
            if(flowerbed[0] == 0){
                return n==0 || n==1;
            }else{
                return n==0;
            }
        }
        for(int i=0;i<sz;i++){
            if(i==0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            else if(i==sz-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            else if(i != 0 && i != (sz-1) && flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            if(n<=0){
                return true;
            }
        }
        return false;
    }
};