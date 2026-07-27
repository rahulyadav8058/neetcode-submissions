class Solution {
   public:
    // bool func(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& ans, int& val) {
    //     if (i == heights.size() - 1 || j == heights[0].size() - 1) {
    //         if (val == heights[i][j]) {
    //             ans.push_back({i, j});
    //             return true;
    //         }
    //         return false;
    //     }
    //     vector<int> dx = {1, -1, 0, 0};
    //     vector<int> dy = {0, 0, 1, -1};
    //     int temp = false;
    //     for (int k = 0; k < 4; k++) {
    //         int nx = i + dx[k];
    //         int ny = j + dy[k];
    //         if (nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size() &&
    //             val >= heights[nx][ny]) {
    //             if (func(heights, nx, ny, ans, val)) {
    //                 ans.push_back({nx, ny});
    //             }
    //         }
    //     }
    //     return false;
    // }

    void func(vector<vector<int>>& heights, int i, int j, int m, int n,
              vector<vector<bool>>& temp1) {
        if (i == m || j == n) return;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        temp1[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size() &&
                heights[i][j] <= heights[nx][ny] && !temp1[nx][ny]) {
                func(heights, nx, ny, m, n, temp1);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> temp1(m, vector<bool>(n, false));
        vector<vector<bool>> temp2(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            func(heights, i, 0,m,n, temp1);
        }
        for (int j = 0; j < n; j++) {
            func(heights, 0, j,m,n, temp1);
        }
        for (int i = 0; i < m; i++) {
            func(heights, i, n-1,m,n, temp2);
        }
        for (int j = 0; j < n; j++) {
            func(heights, m-1, j, m,n,temp2);
        }
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp1[i][j] && temp2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
