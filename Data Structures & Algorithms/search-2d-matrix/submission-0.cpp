class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int row = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(matrix[mid][0] > target){
                r = mid - 1;
            } else if(matrix[mid][matrix[mid].size() - 1] < target){
                l = mid + 1;
            } else {
                row = mid;
                break;
            }
        }
        if(row == -1){
            return false;
        }
        l = 0;
        r = matrix[row].size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            if(matrix[row][mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
