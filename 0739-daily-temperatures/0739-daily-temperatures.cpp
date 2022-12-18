class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> post(n,0);
        for(int i=n-2;i>=0;i--){
            if(temperatures[i]<temperatures[i+1]){
                post[i] = 1;
            }else{
                if(post[i+1] > 0){
                    int j = i+post[i+1];
                    int flag=0;
                    while(temperatures[j] <= temperatures[i]){
                        if(post[j] == 0){
                            post[i] = 0;
                            flag=1;
                            break;
                        }else{
                            j = j+post[j];
                        }
                    }
                    if(flag==0){
                        // cout<<j<<" j "<<i<<endl;
                        post[i] = j-i;
                    }
                    
                }else{
                    post[i] = 0;
                }
            }
        }
        return post;
    }
};