class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                if(matrix[r][c] == 0){
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        }
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[r].size(); c++){
                if(cols.count(c) || rows.count(r)){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
