class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(),inter.end(),[](auto a, auto b){
            return a[1]<b[1];
        });
        int prevlast = inter[0][1];
        int count =0;
        for(int i=1;i<n;i++){
            if(inter[i][0]<prevlast){
                count ++;
            }
            else{
                prevlast = inter[i][1];
            }
        }
        return count;
    }
};
