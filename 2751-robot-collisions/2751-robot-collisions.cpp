class Solution {
public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         vector<int> ans;
//         int n = positions.size();
//         map<int,int> mp;
//         int flag = 0;
//         for(int i=1;i<directions.size();i++){
//             if(directions[i] != directions[i-1]){
//                 flag=1;
//             }
//         }
//         if(flag == 0)
//             return healths;
//         vector<vector<int>> fin;
//         for(int i=0;i<n;i++){
//             int dir=1;
//             if(directions[i] == 'L'){
//                 dir = 0;
//             }
//             mp[positions[i]] = i;
//             fin.push_back({positions[i] , healths[i] , dir});
//         }
//         sort(fin.begin() , fin.end());
//         stack<vector<int>> st;
//         st.push(fin[0]);
//         for(int i=1;i<fin.size();i++){
//             if(st.size() > 0){
//                 int val = fin[i][1] , flag=0;
//                 while(st.size() > 0 && st.top()[2] == 1 && fin[i][2] == 0){
//                     if(st.top()[1] == fin[i][1]){
//                         st.pop();
//                         flag=1;
//                         break;
//                     }else if(st.top()[1] > fin[i][1]){
//                         auto top = st.top();
//                         st.pop();
//                         flag=1;
//                         st.push({top[0] , top[1]-1 , top[2]});
//                         break;
//                     }else{
//                         st.pop();
//                         val--;
//                     }
//                 }
//                 if(flag == 0){
//                     st.push({fin[i][0] , val , fin[i][2]});
//                 }
//             }else{
//                 st.push(fin[i]);
//             }
            
//         }
//         map<int,int> tt;
//         while(st.size() > 0){
//             auto top = st.top();
//             tt[mp[top[0]]] = top[1];
//             st.pop();
//         }
//         for(auto it: tt){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        int n = positions.size();
        vector<Robot> vals;
        for (int i = 0; i < n; i++) {
            vals.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(vals.begin(), vals.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        vector<Robot> stack;
        for (auto& robot : vals) {
            if (robot.direction == 'R') {
                stack.push_back(robot);
                continue;
            }

            // Check if the robot should be eliminated
            bool gone = false;

            // Process the stack to eliminate robots with lower health
            while (!stack.empty() && stack.back().health <= robot.health && stack.back().direction == 'R') {
                if (stack.back().health == robot.health) {
                    stack.pop_back();
                    gone = true;
                    break;
                }
                robot.health--;
                stack.pop_back();
            }

            // If the robot is not yet eliminated and there is a robot facing right with higher health
            if (!gone && !stack.empty() && stack.back().direction == 'R' && stack.back().health > robot.health) {
                stack.back().health--;
                gone = true;
            }

            // If the robot is not eliminated, add it to the stack
            if (!gone) {
                stack.push_back(robot);
            }
        }

        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });

        vector<int> result;
        for (const auto& robot : stack) {
            result.push_back(robot.health);
        }

        return result;
    }
};