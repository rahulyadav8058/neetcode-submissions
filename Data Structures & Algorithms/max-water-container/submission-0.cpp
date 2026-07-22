class Solution {
public:
    int maxArea(vector<int>& heights) {
        int j =heights.size()-1;
        int i=0;
        int ans =0;
        while(i<j){
            int amount = min(heights[i],heights[j])*(j-i);
            ans = max(ans,amount);
            if(heights[i]>=heights[j]){
                j--;
            }else {
                i++;
            }
        }
        return ans;
    }
};
