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
        auto &m2 = m[key];
        auto it = m2.upper_bound(timestamp);
        if(it == m2.begin()){
            return "";
        }
        return prev(it)->second;
    }
};
