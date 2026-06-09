class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> ms;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!ms.empty() && temperatures[i] > ms.top().first){
                res[ms.top().second] = i - ms.top().second;
                ms.pop();
            }
            ms.push({temperatures[i], i});
        }
        return res;
    }
};
