class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ans = 0.0;
        vector<double> prev;
        if(query_row == 0){
            return poured == 0 ? ans : poured > 1.0 ? 1 : poured;
        }
        prev.push_back((double)poured*1.0);
        double rem;
        for(int i=1;i<=query_row;i++){
            vector<double> temp;
            int sz = prev.size();
            for(int i=0;i<sz+1;i++){
                if(i == 0){
                    rem = prev[i]-1;
                    if(rem > 0)
                        temp.push_back((rem)/2.0);
                    else
                        temp.push_back(0.0);
                }else if(i == sz){
                    rem = prev[i-1]-1;
                    if(rem>0)
                        temp.push_back((rem)/2.0);
                    else{
                        temp.push_back(0.0);
                    }
                }else{
                    rem = 0;
                    if(prev[i-1] > 1.0){
                        rem+=prev[i-1]-1.0;
                    }
                    if(prev[i] > 1.0){
                        rem+=prev[i]-1.0;
                    }
                    if(rem > 0)
                        temp.push_back((rem)/2.0);
                    else
                        temp.push_back(0.0);
                }
            }
            prev = temp;
            // for(auto it: prev){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        return prev[query_glass] > 1.0 ? 1.0 : prev[query_glass];
    }
};