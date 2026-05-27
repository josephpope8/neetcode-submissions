class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        bool neg = false;
        if(n < 0){
            neg = true;
            n = abs(n);
        }
        double res = x;
        for(int i = 0; i < n - 1; i++){
            res *= x;
        }
        if(neg){
            res = 1/res;
        }
        return res;
    }
};
