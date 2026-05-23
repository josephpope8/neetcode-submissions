class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key)){
            auto addr = addresses[key];
            order.erase(addr);
            order.push_back(key);
            addr = --order.end();
            addresses[key] = addr;
            return m[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            m[key] = value;
            auto addr = addresses[key];
            order.erase(addr);
            order.push_back(key);
            addr = --order.end();
            addresses[key] = addr;
        }
        else if(m.size() == capacity){
            int lru = order.front();
            m.erase(lru);
            addresses.erase(lru);
            order.pop_front();
            
            m[key] = value;
            order.push_back(key);
            auto addr = --order.end();
            addresses[key] = addr;
        } else {
            m[key] = value;
            order.push_back(key);
            auto addr = --order.end();
            addresses[key] = addr;
        }
    }
private:
    int capacity;
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> addresses;
    list<int> order;
};