class UndergroundSystem {
public:
//     UndergroundSystem() {
        
//     }
//     map<int , pair<string , int>> mpIn;
//     int n=0;
//     map<pair<string , string> , pair<double , double>> ans;
//     void checkIn(int id, string stationName, int t) {
//         mpIn[id] = {stationName , t};
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         string st = mpIn[id].first;
//         int start = mpIn[id].second;
//         mpIn.erase(id);
//         if(ans.find({st , stationName}) != ans.end()){
//             double temp = ans[{st , stationName}].first;
//             double cnt = ans[{st , stationName}].second+1;
//             cout<<cnt<<" Count"<<endl;
//             double calc = ((temp*1.0*(cnt-1)+abs(t-start))*1.0)/(cnt*1.0);
//             cout<<calc<<" "<<st<<" "<< stationName<<" "<<temp<<" "<<abs(t-start)<<endl;
//             ans[{st , stationName}] = {calc , cnt};
//         }else if(ans.find({stationName , st}) != ans.end()){
//             double temp = ans[{stationName , st}].first;
//             double cnt = ans[{stationName , st}].second+1;
//             double calc = ((temp*1.0*(cnt-1)+abs(t-start))*1.0)/(cnt*1.0);
//             cout<<calc<<" "<<stationName<<" "<< st <<endl;
//             ans[{stationName , st}] = {calc , cnt};
//         }else{
//             ans[{stationName , st}] = {abs(start - t) , 1};
//             ans[{st , stationName}] = {abs(start - t) , 1};
//         }
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         double finalAns = 0.0;
//         if(ans.find({startStation , endStation}) != ans.end()){
//             finalAns+=ans[{startStation , endStation}].first;
//         }
//         return finalAns;
        
//     }
    
    
    
    
    unordered_map<int, pair<string, int>> checkInMap; // Uid - {StationName, Time}
    unordered_map<string, pair<double, int>> routeMap; // RouteName - {TotalTime, Count}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id); // Remove after using it which will not make HashTable big
            
        string routeName = checkIn.first + "_" + stationName;
        routeMap[routeName].first += t - checkIn.second;
        routeMap[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = routeMap[routeName];
        return route.first / route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */