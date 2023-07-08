class Solution {
public:
    
    long long int putMarbles(vector<int>& w, int k) {
        if(k >= w.size()){
            return 0;
         }
        if(k==1){
            return 0;
        }
        k-=1;
        long long int maxi = 0,mini = 0;
        vector<long long int> fir , sec;
        for(long long int i = 0;i<w.size()-1;i++){
            int temp = w[i]+w[i+1];
            // cout<<temp<<endl;
            sec.push_back(temp);
        }
        sort(sec.begin() , sec.end());
        for(long long int i = 0;i<w.size()-1;i++){
            int temp = w[i]+w[i+1];
            // cout<<temp<<endl;
            fir.push_back(temp);
        }
        sort(fir.begin() , fir.end() , greater<long long int>());
        for(long long int i =0;i<k;i++){
            maxi = maxi + fir[i];
            // cout<<maxi<<endl;
        }
        for(long long int i =0;i<k;i++){
            mini = mini + sec[i];
            // cout<<mini<<endl;
        } 
        long long int finalans = maxi - mini;
        // cout<<finalans<<endl;
        return finalans;
    }
};