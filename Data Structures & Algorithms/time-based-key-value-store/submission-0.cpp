class TimeMap {
private:
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key)){
            return "";
        }
        map<int, string> &m2 = m[key];
        for(auto it = m2.rbegin(); it != m2.rend(); ++it){
            if(it->first <= timestamp){
                return it->second;
            }
        }
        return "";
    }
};
