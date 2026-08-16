class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  m = matrix.size();
        int n = matrix[0].size();
        int left =0,right = m-1;
        int row =-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(matrix[mid][0] == target)return true;
            if(matrix[mid][0]<target){
                row = mid;
                left = mid+1;

            }else{
                right = mid-1;
            }
        }
        if(row==-1)return false;

        left= 0,right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(matrix[row][mid] == target)return true;
            if(matrix[row][mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};
