class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res(matrix.size()*matrix[0].size());
        int r = 0;
        int c = 0;
        bool row = false;
        bool pos = true;
        int i = 0;
        int rowRightLim = matrix.size() - 1;
        int rowLeftLim = 1;
        int colUpLim = matrix[0].size() - 1;
        int colBotLim = 0;
        while(i < res.size()){
            cout << r << " " << c << " | ";
            res[i] = matrix[r][c];
            i++;
            if(row && pos){
                if(r == rowRightLim){
                    row = false;
                    pos = false;
                    rowRightLim--;
                    c--;
                } else {
                    r++;
                }
            } else if(!row && pos){
                if(c == colUpLim){
                    row = true;
                    pos = true;
                    r++;
                    colUpLim--;
                } else {
                    c++;
                }
            } else if(row && !pos){
                if(r == rowLeftLim){
                    row = false;
                    pos = true;
                    rowLeftLim++;
                    c++;
                } else {
                    r--;
                }
            } else {
                if(c == colBotLim){
                    row = true;
                    pos = false;
                    r--;
                    colBotLim++;
                } else {
                    c--;
                }
            }
        }
        return res;
    }
};
