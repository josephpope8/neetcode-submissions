class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++){
            int comp = target - numbers[i];
            int l = i + 1;
            int r = numbers.size() - 1;
            while(l <= r){
                int mid = (l + r)/2;
                if(numbers[mid] == comp){
                    return {i + 1, mid + 1};
                }
                if(numbers[mid] > comp){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return {};
    }
};
