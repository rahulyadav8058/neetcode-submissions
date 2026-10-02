class Solution {
public:

    bool isSafe(vector<vector<int>>& grid, int row, int col, int n) {

        int r = row - 1;
        int c = col - 1;

        while(r >= 0 && c >= 0) {
            if(grid[r][c] == 1)
                return false;

            r--;
            c--;
        }

        r = row - 1;
        c = col + 1;

        while(r >= 0 && c < n) {
            if(grid[r][c] == 1)
                return false;

            r--;
            c++;
        }

        r = row + 1;
        c = col - 1;

        while(r < n && c >= 0) {
            if(grid[r][c] == 1)
                return false;

            r++;
            c--;
        }

        r = row + 1;
        c = col + 1;

        while(r < n && c < n) {
            if(grid[r][c] == 1)
                return false;

            r++;
            c++;
        }

        // Same column
        r = row - 1;

        while(r >= 0) {
            if(grid[r][col] == 1)
                return false;

            r--;
        }

        return true;
    }

    int func(vector<vector<int>>& grid, int ind, int n) {

        if(ind == n)
            return 1;

        int count = 0;

        for(int i = 0; i < n; i++) {

            if(isSafe(grid, ind, i, n)) {

                grid[ind][i] = 1;

                count += func(grid, ind + 1, n);

                grid[ind][i] = 0;
            }
        }

        return count;
    }

    int totalNQueens(int n) {

        vector<vector<int>> grid(n, vector<int>(n, 0));

        return func(grid, 0, n);
    }
};