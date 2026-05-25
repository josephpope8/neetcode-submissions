class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        stream = nums;
    }
    
    int add(int val) {
        stream.push_back(val);
        priority_queue<int> pq(stream.begin(), stream.end());
        for(int i = 0; i < k - 1; i++){
            pq.pop();
        }
        return pq.top();
    }
private:
    vector<int> stream;
    int k;
};
