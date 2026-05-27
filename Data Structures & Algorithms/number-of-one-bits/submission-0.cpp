class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n > 0){
            if(n%2 != 0){
                num++;
            }
            n /= 2;
        }
        return num;
    }
};
