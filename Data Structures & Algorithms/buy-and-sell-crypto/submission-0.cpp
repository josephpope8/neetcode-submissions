class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int min = 101;
        for(int x : prices){
            if(x - min > maxP){
                maxP = x - min;
            }
            if(x < min){
                min = x;
            }
        }
        return maxP;
    }
};
