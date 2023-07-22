class Solution {
public:
    vector<pair<int,int>> moves = {{2 , 1} , {-2 , -1} , {-2 , 1}, {2 , -1} , {1 , 2}, {-1 , -2}, {-1 , 2}, {1 , -2}};
    double solve(int n , int k , int r , int c){
        queue<pair<double , pair<int,int>>> q;
        q.push({1.0 , {r , c}});
        double temp = 1.0;
        while(k--){
            int sz = q.size();
            cout<<sz<<" sz"<<endl;
            while(sz--){
                auto top = q.front();
                int i = top.second.first , j = top.second.second;
                q.pop();
                for(auto it: moves){
                    if((i+it.first) >= n || (i+it.first) < 0){
                        continue;
                    }
                    if((j+it.second) >= n || (j+it.second) < 0){
                        continue;
                    }
                    temp = top.first;
                    temp = (temp)/(8*1.0);
                    // cout<<temp<<" temp"<<endl;
                    q.push({temp , {i+it.first , j+it.second}});
                }
            }
        }
        int sz = q.size();
        // int val = q.front().first;
        // cout<<sz<<" sz "<<temp<<endl;
        return sz*1.0*temp;
    }
    double knightProbability(int N, int K, int r, int c) {
        // return solve(n , k , r , c);
        vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
		vector<vector<double>> dp(N,vector<double>(N,0));
		dp[r][c]=1;
		for(int i=1;i<=K;i++){
			vector<vector<double>> tem(N,vector<double>(N,0));
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					for(int v=0;v<8;v++){
						int x=j+dir[v][0];
						int y=k+dir[v][1];
						if(x<0 || y<0 || x>=N || y>=N){
							continue;
						}
						tem[j][k]+=dp[x][y];
					}
				}
			}
			dp=tem;
		}
		double rec=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				rec+=dp[i][j];
			}
		double res=rec/pow(8,K);
		return res;
    }
};