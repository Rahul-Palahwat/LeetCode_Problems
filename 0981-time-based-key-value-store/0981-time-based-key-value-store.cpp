class TimeMap {
public:
    unordered_map<string , unordered_map<int , string>> mp;
    unordered_map<string , vector<int>> time;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
        time[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        auto &v = time[key];
        int low = 0 , high = v.size()-1;
        int index = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(v[mid]<=timestamp){
                low = mid+1;
                index = mid;
            }else{
                high = mid-1;
            }
        }
        if(index == -1){
            return "";
        }
        return mp[key][time[key][index]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */