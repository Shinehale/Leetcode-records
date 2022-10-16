class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for (int i = 0; i < matrix.size(); i++)
            matrix[i].resize(n);
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int num = 1;

        while(true){
            for(int i = left; i <= right; i++) matrix[up][i] = num++;
            if ( up++ >= down ) break;
            for(int i = up; i <= down; i++) matrix[i][right] = num++;
            if (right-- <= left) break;
            for(int i = right; i >= left; i--) matrix[down][i] = num++;
            if (down-- <= up) break;
            for(int i= down ; i >= up; i--) matrix[i][left] = num++;
            if (left++ >= right) break;
        }
        return matrix;
    }
};