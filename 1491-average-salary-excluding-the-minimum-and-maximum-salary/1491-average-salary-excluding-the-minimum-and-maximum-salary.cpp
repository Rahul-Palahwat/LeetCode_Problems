class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0.0;
        int n = salary.size();
        sort(salary.begin() , salary.end());
        for(int i=1;i<n-1;i++){
            ans+=salary[i];
        }
        return (ans*1.0)/((n-2));
    }
};