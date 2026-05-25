class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int x : stones){
            maxH.push(x);
        }
        while(maxH.size() > 1){
            int s1 = maxH.top();
            maxH.pop();
            int s2 = maxH.top();
            maxH.pop();
            if(s1 != s2){
                maxH.push(abs(s2 - s1));
            }
        }
        if(maxH.empty()){
            return 0;
        }
        return maxH.top();
    }
};
