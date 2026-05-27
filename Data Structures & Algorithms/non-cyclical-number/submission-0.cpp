class Solution {
public:
    int sum(int n){
        int s = 0;
        while(n > 0){
            s += (n%10)*(n%10);
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1){
            if(seen.count(n)){
                return false;
            }
            seen.insert(n);
            n = sum(n);
        }
        return true;
    }
};
